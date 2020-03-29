#include "UtilityPCH.h"

#include <string>
#include <chrono>
#include <vector>
#include <initializer_list>

#include "Logger.h"
#include "Console.h"

namespace Logging
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   Logger::Logger( const char* a_LoggerName, const LogLevel a_BaseLoggingLevel, const int& a_TextColor, const int& a_BGColor, const char* a_LoggingFormat ) :
      m_LoggerName( a_LoggerName ),
      m_BaseLoggingLevel( a_BaseLoggingLevel ),
      m_TextColor( a_TextColor ),
      m_BGColor( a_BGColor ),
      m_ExecutionQueue(),
      m_LastMessageTimeStamp( std::chrono::steady_clock::now() )
   {
      CompileFormat( m_ExecutionQueue, a_LoggingFormat );
      // This->Log("Logger Created!");
   }

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   // Log Without Formattables
   void Logger::Trace( const char* a_Message )
   {
      if ( m_BaseLoggingLevel <= TRACE )
         Logger::Log( TRACE, a_Message );
   }

   void Logger::Debug( const char* a_Message )
   {
      if ( m_BaseLoggingLevel <= DEBUG )
         Logger::Log( DEBUG, a_Message );
   }

   void Logger::Info( const char* a_Message )
   {
      if ( m_BaseLoggingLevel <= INFO )
         Logger::Log( INFO, a_Message );
   }

   void Logger::Warn( const char* a_Message )
   {
      if ( m_BaseLoggingLevel <= WARNING )
         Logger::Log( WARNING, a_Message );
   }

   void Logger::Error( const char* a_Message )
   {
      if ( m_BaseLoggingLevel <= ERR_OR )
         Logger::Log( ERR_OR, a_Message );
   }

   void Logger::Fatal( const char* a_Message )
   {
      if ( m_BaseLoggingLevel <= FATAL )
         Logger::Log( FATAL, a_Message );
   }

   // Log With Formattables
   void Logger::Trace( const char* a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
   {
      if ( m_BaseLoggingLevel <= TRACE )
         Logger::Log( TRACE, a_Message, a_Formattables );
   }

   void Logger::Debug( const char* a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
   {
      if ( m_BaseLoggingLevel <= DEBUG )
         Logger::Log( DEBUG, a_Message, a_Formattables );
   }

   void Logger::Info( const char* a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
   {
      if ( m_BaseLoggingLevel <= INFO )
         Logger::Log( INFO, a_Message, a_Formattables );
   }

   void Logger::Warn( const char* a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
   {
      if ( m_BaseLoggingLevel <= WARNING )
         Logger::Log( WARNING, a_Message, a_Formattables );
   }

   void Logger::Error( const char* a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
   {
      if ( m_BaseLoggingLevel <= ERR_OR )
         Logger::Log( ERR_OR, a_Message, a_Formattables );
   }

   void Logger::Fatal( const char* a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
   {
      if ( m_BaseLoggingLevel <= FATAL )
         Logger::Log( FATAL, a_Message, a_Formattables );
   }

   /***********************\
   \*****   SETTERS   *****/
   void Logger::SetBaseLoggingLevel( const LogLevel& a_LoggingLevel )
   {
      m_BaseLoggingLevel = a_LoggingLevel;
   }

   void Logger::SetTextColor( const int& a_TextColor )
   {
      m_TextColor = a_TextColor;
   }

   void Logger::SetBackgroundColor( const int& a_BGColor )
   {
      m_BGColor = a_BGColor;
   }

   void Logger::SetFormat( const char* a_Format )
   {
      CompileFormat( m_ExecutionQueue, a_Format );
   }

   /***********************\
   \*****   GETTERS   *****/
   const std::string Logger::GetName() const
   {
      return m_LoggerName;
   }

   /*********************************\
   \*****   PRIVATE-FUNCTIONS   *****/
   void Logger::Log( const LogLevel& a_LogLevel, const char*& a_Message )
   {
      Console::Get().Log( *this, a_LogLevel, a_Message );
   }

   void Logger::Log( const LogLevel& a_LogLevel, const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
   {
      Console::Get().Log( *this, a_LogLevel, a_Message, a_Formattables );
   }

   void Logger::CompileFormat( std::vector<FormatAction>& a_ExecutionQueue, const char* a_FormatString )
   {
      a_ExecutionQueue.clear();
      const char* x_TextStart = a_FormatString;
      const char* i_ptr = a_FormatString;

      while ( *i_ptr != 0 )
      {
         switch ( *i_ptr )
         {
            case FCC_DATE:
            {
               if ( i_ptr - x_TextStart > 0 )
                  a_ExecutionQueue.emplace_back( x_TextStart, i_ptr - x_TextStart );

               if ( *( i_ptr + 1 ) != 0 )
               {
                  if ( IsDateControlCharacter( *i_ptr ) )
                     a_ExecutionQueue.emplace_back( FormatAction::ActionType::FORMAT_DATE, *( i_ptr + 1 ) );
                  else
                     a_ExecutionQueue.emplace_back( FormatAction::ActionType::DATE_COMPILE_ERROR, *( i_ptr + 1 ) );

                  x_TextStart = i_ptr + 2;
                  i_ptr++;
               }
               else
               {
                  a_ExecutionQueue.emplace_back( FormatAction::ActionType::DATE_COMPILE_ERROR, '?' );
                  x_TextStart = i_ptr + 1;
               }
               break;
            }

            case FCC_LOGGER:
            {
               if ( i_ptr - x_TextStart > 0 )
                  a_ExecutionQueue.emplace_back( x_TextStart, i_ptr - x_TextStart );

               if ( *( i_ptr + 1 ) != 0 )
               {
                  switch ( *( i_ptr + 1 ) )
                  {
                     case LCC_MESSAGE:
                        a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOG_MESSAGE, LCC_MESSAGE );
                        break;
                     case LCC_LOG_LEVEL:
                        a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOG_LEVEL, LCC_LOG_LEVEL );
                        break;
                     case LCC_LOGGER_NAME:
                        a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOGGER_NAME, LCC_LOGGER_NAME );
                        break;
                     case LCC_AMPERSAND:
                        a_ExecutionQueue.emplace_back( FormatAction::ActionType::AMPERSAND, LCC_AMPERSAND );
                        break;
                     case LCC_SMARTTIME:
                        a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOG_TIME_DIFFERENCE, LCC_SMARTTIME );
                        break;
                     case LCC_SECONDS:
                        a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOG_TIME_DIFFERENCE, LCC_SECONDS );
                        break;
                     case LCC_MILLISECONDS:
                        a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOG_TIME_DIFFERENCE, LCC_MILLISECONDS );
                        break;
                     case LCC_MICROSECONDS:
                        a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOG_TIME_DIFFERENCE, LCC_MICROSECONDS );
                        break;
                     case LCC_NANOSECONDS:
                        a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOG_TIME_DIFFERENCE, LCC_NANOSECONDS );
                        break;
                     case LCC_THREAD_ID:
                        a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOG_THREAD_ID, LCC_THREAD_ID );
                        break;
                     case LCC_PROCESS_ID:
                        a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOG_PROCESS_ID, LCC_PROCESS_ID );
                        break;
                     default:
                        a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOGGER_COMPILE_ERROR, '?' );
                        break;
                  }

                  x_TextStart = i_ptr + 2;
                  i_ptr++;
               }
               else
               {
                  a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOGGER_COMPILE_ERROR, '?' );
                  x_TextStart = i_ptr + 1;
               }
               break;
            }

            default:
               break;
         }
         i_ptr++;
      }

      if ( i_ptr - x_TextStart > 0 )
         a_ExecutionQueue.emplace_back( x_TextStart, i_ptr - x_TextStart );
   }

   std::string Logger::ExecuteQueue( const LogLevel& a_LogLevel, const char*& a_Message ) const
   {
      std::string x_ConsoleMessage;
      x_ConsoleMessage.reserve( strlen( a_Message ) + 250 ); // TWEAK

      for ( FormatAction itr : m_ExecutionQueue )
      {
         x_ConsoleMessage += itr.ExecuteAction( *this, a_LogLevel, a_Message );
      }
      m_LastMessageTimeStamp = std::chrono::steady_clock::now();

      return x_ConsoleMessage;
   }

   /**********************\
   \*****   NESTED   *****/
   Logger::FormatAction::FormatAction( const FormatAction::ActionType& a_ActionType, const char& a_FormatChar ) :
      m_FormatChar( a_FormatChar ),
      m_ActionType( a_ActionType ),
      m_ReturnText()
   {}

   Logger::FormatAction::FormatAction( const char*& a_TextStart, const size_t a_Length, const char& a_FormatChar ) :
      m_FormatChar( a_FormatChar ),
      m_ActionType( SIMPLE_TEXT ),
      m_ReturnText( a_TextStart, a_Length )
   {}

   std::string Logger::FormatAction::ExecuteAction( const Logger& a_Logger, const LogLevel& a_LogLevel, const char*& a_Message )
   {
      switch ( m_ActionType )
      {
         case SIMPLE_TEXT:
            return m_ReturnText;

         case FORMAT_DATE:
         {
            char x_Buffer[40]; // TWEAK
            const char x_Format[] = { '%', m_FormatChar, 0 };
            const time_t x_RawTime = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
            struct tm* x_TimeNow = localtime( &x_RawTime );
            size_t x_TimeStringLength = strftime( x_Buffer, 40, x_Format, x_TimeNow ); // TWEAK

            m_ReturnText = std::string( x_Buffer, x_TimeStringLength );

            return m_ReturnText;
         }

         case LOGGER_NAME:
            return a_Logger.GetName();

         case LOG_LEVEL:
         {
            switch ( a_LogLevel )
            {
               case TRACE:
                  return "TRACE";

               case DEBUG:
                  return "DEBUG";

               case INFO:
                  return "INFO";

               case WARNING:
                  return "WARNING";

               case ERR_OR:
                  return "ERROR";

               case FATAL:
                  return "FATAL";

               default:
                  throw; // TODO Exception Unknown Logging::LogLevel
            }
         }

         case LOG_MESSAGE:
            return a_Message;

         case LOG_TIME_DIFFERENCE:
         {
            std::chrono::duration<float> x_TimeDiff = std::chrono::steady_clock::now() - a_Logger.m_LastMessageTimeStamp;
            float x_Ticks = x_TimeDiff.count();
            const char* x_TimeSymbols[] = { "s", "ms", "us", "ns" };

            switch ( m_FormatChar )
            {
               case LCC_SMARTTIME:
               {
                  for ( int i = 0; i < 4; i++ )
                  {
                     if ( x_Ticks < 1 )
                        x_Ticks *= 1000.0f;
                     else
                        return std::to_string( x_Ticks ) + x_TimeSymbols[i];
                  }
                  return std::to_string( x_Ticks ) + x_TimeSymbols[3];
               }

               case LCC_SECONDS:
                  return std::to_string( x_Ticks ) + x_TimeSymbols[0];

               case LCC_MILLISECONDS:
                  return std::to_string( x_Ticks * 1000.0f ) + x_TimeSymbols[1];

               case LCC_MICROSECONDS:
                  return std::to_string( x_Ticks * 1000000.0f ) + x_TimeSymbols[2];

               case LCC_NANOSECONDS:
                  return std::to_string( x_Ticks * 1000000000.0f ) + x_TimeSymbols[3];

               default:
                  throw; // TODO Exception Unknown Time Difference Control Character
            }
            break;
         }

         case LOG_THREAD_ID:
            throw "Not Implemented."; // TODO Implement This.
            break;

         case LOG_PROCESS_ID:
            throw "Not Implemented."; // TODO Implement This.
            break;

         case AMPERSAND:
            return "&";

         case DATE_COMPILE_ERROR:
         {
            m_ReturnText.reserve( 4 );
            m_ReturnText += "?%";
            m_ReturnText += m_FormatChar;
            m_ReturnText += '?';
            return m_ReturnText;
         }

         case LOGGER_COMPILE_ERROR:
         {
            m_ReturnText.reserve( 4 );
            m_ReturnText += "?&";
            m_ReturnText += m_FormatChar;
            m_ReturnText += '?';
            return m_ReturnText;
         }
      }
      throw; // TODO Exception Unknown FormatAction::ActionType
   }
}
