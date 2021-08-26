#include "FlarePCH.h"
#include "Logger.h"
#include "LoggingContext.h"

namespace Flare::Logging
{
   /*****   CLASS   C-TOR D-TOR  *****/
   LoggingContext::LoggingContext( const Logger& a_Logger, LogLevel a_LogLevel, const std::string& a_Message ) :
      m_Logger( a_Logger ),
      m_LogLevel( a_LogLevel ),
      m_Message( a_Message ),
      m_LogTime( std::chrono::system_clock::now() )
   {}
}

typename std::format_parse_context::iterator std::formatter<Flare::Logging::LoggingContext>::parse( std::format_parse_context& a_ParseContext )
{
   using U_C_Itr = std::format_parse_context::const_iterator;
   U_C_Itr x_Itr = a_ParseContext.begin();
   U_C_Itr x_ItrEnd = a_ParseContext.end();
   U_C_Itr x_SubFormatBegin = U_C_Itr();

   m_Indicator = Flare::Logging::ConvertToLoggingControlCharacter( *x_Itr );
   if ( m_Indicator == Flare::Logging::LoggingControlCharacter::UNDEFINED || m_Indicator == Flare::Logging::LoggingControlCharacter::ERROR_LCC )
      throw; // TODO Exception : Invalid Format Character.

   // Set potential begin of sub format and find the end of it.
   x_Itr++;
   x_SubFormatBegin = x_Itr;
   while ( x_Itr != x_ItrEnd && *x_Itr != '}' )
      x_Itr++;

   // Create a string for SubFormat.
   if ( x_Itr - x_SubFormatBegin ) // Essentially, if result > 0
      m_SubFormat = std::format( "{{:{}}}", std::string( x_SubFormatBegin, x_Itr ) );
   else
      m_SubFormat = "{}";

   return x_Itr;
}

typename std::format_context::iterator std::formatter<Flare::Logging::LoggingContext>::format( Flare::Logging::LoggingContext a_LoggingContext, std::format_context& a_FormatContext )
{
   auto x_BackInserter = a_FormatContext.out();

   switch ( m_Indicator )
   {
      case Flare::Logging::LoggingControlCharacter::UNDEFINED:
         x_BackInserter = static_cast<char>( Flare::Logging::LoggingControlCharacter::UNDEFINED );
         break;

      case Flare::Logging::LoggingControlCharacter::MESSAGE:
         x_BackInserter = std::vformat_to( x_BackInserter, m_SubFormat, std::make_format_args( a_LoggingContext.m_Message ) );
         break;

      case Flare::Logging::LoggingControlCharacter::LOG_LEVEL_L:
      {
         const char* x_LogLevelName = Flare::Logging::LogLevelNamesLower[static_cast<int>( a_LoggingContext.m_LogLevel )];
         x_BackInserter = std::vformat_to( x_BackInserter, m_SubFormat, std::make_format_args( x_LogLevelName ) );
         break;
      }

      case Flare::Logging::LoggingControlCharacter::LOG_LEVEL_P:
      {
         const char* x_LogLevelName = Flare::Logging::LogLevelNamesPascal[static_cast<int>( a_LoggingContext.m_LogLevel )];
         x_BackInserter = std::vformat_to( x_BackInserter, m_SubFormat, std::make_format_args( x_LogLevelName ) );
         break;
      }

      case Flare::Logging::LoggingControlCharacter::LOG_LEVEL_U:
      {
         const char* x_LogLevelName = Flare::Logging::LogLevelNamesUpper[static_cast<int>( a_LoggingContext.m_LogLevel )];
         x_BackInserter = std::vformat_to( x_BackInserter, m_SubFormat, std::make_format_args( x_LogLevelName ) );
         break;
      }

      case Flare::Logging::LoggingControlCharacter::LOGGER_NAME:
         x_BackInserter = std::vformat_to( x_BackInserter, m_SubFormat, std::make_format_args( a_LoggingContext.m_Logger.GetName() ) );
         break;

      case Flare::Logging::LoggingControlCharacter::ELAPSED:
      case Flare::Logging::LoggingControlCharacter::ELAPSED_SECONDS:
      case Flare::Logging::LoggingControlCharacter::ELAPSED_MILLISECONDS:
      case Flare::Logging::LoggingControlCharacter::ELAPSED_MICROSECONDS:
      case Flare::Logging::LoggingControlCharacter::ELAPSED_NANOSECONDS:
      {
         std::chrono::duration<float> x_TimeDiff = a_LoggingContext.m_LogTime - a_LoggingContext.m_Logger.GetLastMessageTimeStamp();
         float x_TimeElapsed = x_TimeDiff.count();
         const char* x_TimeUnit;

         // Nested switch case, I don't know how this affects perfomance or readability yet.
         switch ( m_Indicator )
         {
            case Flare::Logging::LoggingControlCharacter::ELAPSED:
            {
               for ( int i = 0; i < 4; i++ )
               {
                  if ( x_TimeElapsed < 1 )
                  {
                     x_TimeElapsed *= 1'000.0f;
                     x_TimeUnit = Flare::Logging::TimeUnits[i];
                  }
                  else
                     break;
               }
               break;
            }

            case Flare::Logging::LoggingControlCharacter::ELAPSED_SECONDS:
               x_TimeUnit = Flare::Logging::TimeUnits[0];
               break;

            case Flare::Logging::LoggingControlCharacter::ELAPSED_MILLISECONDS:
               x_TimeUnit = Flare::Logging::TimeUnits[1];
               x_TimeElapsed *= 1'000.0f;
               break;

            case Flare::Logging::LoggingControlCharacter::ELAPSED_MICROSECONDS:
               x_TimeUnit = Flare::Logging::TimeUnits[2];
               x_TimeElapsed *= 1'000'000.0f;
               break;

            case Flare::Logging::LoggingControlCharacter::ELAPSED_NANOSECONDS:
               x_TimeUnit = Flare::Logging::TimeUnits[3];
               x_TimeElapsed *= 1'000'000'000.0f;
               break;
         }

         m_SubFormat += "{}";
         x_BackInserter = std::vformat_to( x_BackInserter, m_SubFormat, std::make_format_args( x_TimeElapsed, x_TimeUnit ) );
         break;
      }

      case Flare::Logging::LoggingControlCharacter::TIME:
         x_BackInserter = std::vformat_to( x_BackInserter, m_SubFormat, std::make_format_args( a_LoggingContext.m_LogTime ) );
         break;

      case Flare::Logging::LoggingControlCharacter::THREAD_ID:
         throw; // TODO
         break;

      case Flare::Logging::LoggingControlCharacter::ERROR_LCC:
         x_BackInserter = static_cast<char>( Flare::Logging::LoggingControlCharacter::ERROR_LCC );
         break;

      default:
         throw; // TODO Exception : Unexpected enum.
   }

   return x_BackInserter;
}