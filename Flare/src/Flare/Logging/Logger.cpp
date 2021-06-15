#include "FlarePCH.h"
#include "Logger.h"
#include "Console.h"

#include <string>
#include <format>
#include <chrono>
#include <vector>
#include <utility>

namespace Flare::Logging
{
   /*****   CLASS   C-TOR D-TOR  *****/
   Logger::Logger( const LoggerParameters& a_Parameters ) noexcept :
      m_Parameters( a_Parameters ),
      m_ActionQueue(),
      m_LastMessageTimeStamp( std::chrono::steady_clock::now() )
   {
      CompileFormat( m_Parameters.m_FormatString );
   }

   Logger::Logger( LoggerParameters&& a_Parameters ) noexcept :
      m_Parameters( std::move( a_Parameters ) ),
      m_ActionQueue(),
      m_LastMessageTimeStamp( std::chrono::steady_clock::now() )
   {
      CompileFormat( m_Parameters.m_FormatString );
   }

   // Nested Class FormatAction Constructors
   Logger::FormatAction::FormatAction( FormatAction::ActionType a_ActionType, char a_FormatChar ) :
      m_FormatChar( a_FormatChar ),
      m_ActionType( a_ActionType ),
      m_ReturnText()
   {}

   Logger::FormatAction::FormatAction( FormatAction::ActionType a_ActionType, LoggingControlCharacter a_FormatChar ) :
      m_FormatChar( static_cast<char>( a_FormatChar ) ),
      m_ActionType( a_ActionType ),
      m_ReturnText()
   {}

   Logger::FormatAction::FormatAction( const char* a_TextStart, size_t a_Length ) :
      m_FormatChar( 0 ),
      m_ActionType( FormatAction::ActionType::SIMPLE_TEXT ),
      m_ReturnText( a_TextStart, a_Length )
   {}

   /*****   CLASS   FUNCTIONS    *****/
   void Logger::CompileFormat( const char* a_FormatString )
   {
      m_ActionQueue.clear();
      const char* x_TextStart = a_FormatString;
      const char* i_ptr = a_FormatString;

      while ( *i_ptr != 0 )
      {
         FormatControlCharacter x_Char = static_cast<FormatControlCharacter>( *i_ptr );

         switch ( x_Char )
         {
            case FormatControlCharacter::FCC_DATE:
            {
               if ( i_ptr - x_TextStart > 0 ) // Some text was passed over. Add it to the actions.
                  m_ActionQueue.emplace_back( x_TextStart, i_ptr - x_TextStart );

               if ( *( i_ptr + 1 ) != 0 ) // Must have a valid ActionType character.
               {
                  const char x_NextChar = *( i_ptr + 1 );

                  if ( x_NextChar == static_cast<char>( DateTimeControlCharacter::A_PERCENTAGE_SIGN ) )
                     m_ActionQueue.emplace_back( "%", 1 ); // Avoid date time parsing logic if we just want a % char.
                  else if ( IsDateControlCharacter( x_NextChar ) )
                     m_ActionQueue.emplace_back( FormatAction::ActionType::FORMAT_DATE, x_NextChar );
                  else
                     m_ActionQueue.emplace_back( FormatAction::ActionType::DATE_COMPILE_ERROR, x_NextChar );

                  x_TextStart = i_ptr + 2; // Reposition TextStart after control characters.
                  i_ptr++; // Extra incrementation to skip a second character.
               }
               else
               {
                  m_ActionQueue.emplace_back( FormatAction::ActionType::DATE_COMPILE_ERROR, '?' );
                  x_TextStart = i_ptr + 1; // Reposition TextStart after control characters.
               }
               break;
            }

            case FormatControlCharacter::FCC_LOGGER:
            {
               if ( i_ptr - x_TextStart > 0 ) // Some text was passed over. Add it to the actions.
                  m_ActionQueue.emplace_back( x_TextStart, i_ptr - x_TextStart );

               if ( *( i_ptr + 1 ) != 0 ) // Must have a valid ActionType character.
               {
                  LoggingControlCharacter x_NextChar = static_cast<LoggingControlCharacter>( *( i_ptr + 1 ) );

                  switch ( x_NextChar )
                  {
                     case LoggingControlCharacter::MESSAGE:
                        m_ActionQueue.emplace_back( FormatAction::ActionType::LOG_MESSAGE, LoggingControlCharacter::MESSAGE );
                        break;
                     case LoggingControlCharacter::LOG_LEVEL_L:
                        m_ActionQueue.emplace_back( FormatAction::ActionType::LOG_LEVEL, LoggingControlCharacter::LOG_LEVEL_L );
                        break;
                     case LoggingControlCharacter::LOG_LEVEL_U:
                        m_ActionQueue.emplace_back( FormatAction::ActionType::LOG_LEVEL, LoggingControlCharacter::LOG_LEVEL_U );
                        break;
                     case LoggingControlCharacter::LOGGER_NAME:
                        m_ActionQueue.emplace_back( FormatAction::ActionType::LOGGER_NAME, LoggingControlCharacter::LOGGER_NAME );
                        break;
                     case LoggingControlCharacter::AMPERSAND:
                        m_ActionQueue.emplace_back( "&", 1 );
                        break;
                     case LoggingControlCharacter::SMARTTIME:
                        m_ActionQueue.emplace_back( FormatAction::ActionType::LOG_TIME_DIFFERENCE, LoggingControlCharacter::SMARTTIME );
                        break;
                     case LoggingControlCharacter::SECONDS:
                        m_ActionQueue.emplace_back( FormatAction::ActionType::LOG_TIME_DIFFERENCE, LoggingControlCharacter::SECONDS );
                        break;
                     case LoggingControlCharacter::MILLISECONDS:
                        m_ActionQueue.emplace_back( FormatAction::ActionType::LOG_TIME_DIFFERENCE, LoggingControlCharacter::MILLISECONDS );
                        break;
                     case LoggingControlCharacter::MICROSECONDS:
                        m_ActionQueue.emplace_back( FormatAction::ActionType::LOG_TIME_DIFFERENCE, LoggingControlCharacter::MICROSECONDS );
                        break;
                     case LoggingControlCharacter::NANOSECONDS:
                        m_ActionQueue.emplace_back( FormatAction::ActionType::LOG_TIME_DIFFERENCE, LoggingControlCharacter::NANOSECONDS );
                        break;
                     case LoggingControlCharacter::THREAD_ID:
                        m_ActionQueue.emplace_back( FormatAction::ActionType::LOG_THREAD_ID, LoggingControlCharacter::THREAD_ID );
                        break;
                     case LoggingControlCharacter::PROCESS_ID:
                        m_ActionQueue.emplace_back( FormatAction::ActionType::LOG_PROCESS_ID, LoggingControlCharacter::PROCESS_ID );
                        break;
                     default:
                        m_ActionQueue.emplace_back( FormatAction::ActionType::LOGGER_COMPILE_ERROR, LoggingControlCharacter::ERROR_LCC );
                        break;
                  }

                  x_TextStart = i_ptr + 2; // Reposition TextStart after control characters.
                  i_ptr++; // Extra incrementation to skip a second character.
               }
               else
               {
                  m_ActionQueue.emplace_back( FormatAction::ActionType::LOGGER_COMPILE_ERROR, LoggingControlCharacter::ERROR_LCC );
                  x_TextStart = i_ptr + 1; // Reposition TextStart after control characters.
               }
               break;
            }

            default:
               break;
         }
         i_ptr++;
      }

      if ( i_ptr - x_TextStart > 0 ) // Add the final piece of text if there is.
         m_ActionQueue.emplace_back( x_TextStart, i_ptr - x_TextStart );
   }

   std::string Logger::ExecuteQueue( const LoggingContext& a_Context ) const
   {
      std::string x_ConsoleMessage;
      x_ConsoleMessage.reserve( a_Context.m_FormattedMessage.length() + 100 ); // TWEAK

      for ( FormatAction itr : m_ActionQueue )
      {
         std::string x_Output;
         itr.Execute( a_Context, x_Output );
         std::format_to( std::back_inserter( x_ConsoleMessage ), "{}", x_Output ); // TODO : Find a better way to do this.
      }
      m_LastMessageTimeStamp = std::chrono::steady_clock::now();

      return x_ConsoleMessage; // TODO : Use move semantics.
   }

#pragma region Nested FormatAction Functions
   void Logger::FormatAction::Execute( const LoggingContext& a_Context, std::string& /* out */ a_ReturnText )
   {
      switch ( m_ActionType )
      {
         case FormatAction::ActionType::SIMPLE_TEXT:
            a_ReturnText = m_ReturnText;
            break;

         case FormatAction::ActionType::FORMAT_DATE:
         {
            // TODO : There must be a better way to obatain the date and time.
            char x_Buffer[40]; // TWEAK
            const char x_Format[] = { '%', m_FormatChar, 0 };
            const time_t x_RawTime = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
            struct tm x_TimeNow;
            localtime_s( &x_TimeNow, &x_RawTime );
            size_t x_TimeStringLength = strftime( x_Buffer, 40, x_Format, &x_TimeNow ); // TWEAK

            a_ReturnText = std::move( std::string( x_Buffer, x_TimeStringLength ) );
            break;
         }

         case FormatAction::ActionType::LOGGER_NAME:
            a_ReturnText = a_Context.m_Logger.m_Parameters.m_LoggerName;
            break;

         case FormatAction::ActionType::LOG_LEVEL:
         {
            bool x_Upper = static_cast<LoggingControlCharacter>( m_FormatChar ) == LoggingControlCharacter::LOG_LEVEL_U;

            switch ( a_Context.m_LogLevel )
            { // TODO : Use Name array.
               case LogLevel::Trace:
                  a_ReturnText = x_Upper ? "TRACE" : "Trace";
                  break;

               case LogLevel::Debug:
                  a_ReturnText = x_Upper ? "DEBUG" : "Debug";
                  break;

               case LogLevel::Info:
                  a_ReturnText = x_Upper ? "INFO" : "Info";
                  break;

               case LogLevel::Warning:
                  a_ReturnText = x_Upper ? "WARNING" : "Warning";
                  break;

               case LogLevel::Error:
                  a_ReturnText = x_Upper ? "ERROR" : "Error";
                  break;

               case LogLevel::Fatal:
                  a_ReturnText = x_Upper ? "FATAL" : "Fatal";
                  break;

               default:
                  throw; // TODO Exception Unknown Logging::LogLevel
            }
            break;
         }

         case FormatAction::ActionType::LOG_MESSAGE:
            a_ReturnText = a_Context.m_FormattedMessage;
            break;

         case FormatAction::ActionType::LOG_TIME_DIFFERENCE:
         {
            std::chrono::duration<float> x_TimeDiff = std::chrono::steady_clock::now() - a_Context.m_Logger.m_LastMessageTimeStamp;
            float x_Ticks = x_TimeDiff.count();
            const char* x_TimeSymbols[] = { "s", "ms", "us", "ns" };

            LoggingControlCharacter x_TDChar = static_cast<LoggingControlCharacter>( m_FormatChar );

            switch ( x_TDChar )
            {
               case LoggingControlCharacter::SMARTTIME:
               {
                  int i = 0; // Keep i alive after loop in case we reach nanoseconds.
                  for ( ; i < 4; i++ )
                  {
                     if ( x_Ticks < 1 )
                        x_Ticks *= 1000.0f;
                     else
                        break;
                  }

                  a_ReturnText = std::move( std::format( "{:.3f}{}", x_Ticks, x_TimeSymbols[i] ) );
                  break;
               }

               case LoggingControlCharacter::SECONDS:
                  a_ReturnText = std::move( std::format( "{:.3f}{}", x_Ticks, x_TimeSymbols[0] ) );
                  break;

               case LoggingControlCharacter::MILLISECONDS:
                  a_ReturnText = std::move( std::format( "{:.3f}{}", x_Ticks, x_TimeSymbols[1] ) );
                  break;

               case LoggingControlCharacter::MICROSECONDS:
                  a_ReturnText = std::move( std::format( "{:.3f}{}", x_Ticks, x_TimeSymbols[2] ) );
                  break;

               case LoggingControlCharacter::NANOSECONDS:
                  a_ReturnText = std::move( std::format( "{:.3f}{}", x_Ticks, x_TimeSymbols[3] ) );
                  break;

               default:
                  throw; // TODO Exception Unknown Time Difference Control Character
            }
            break;
         }

         case FormatAction::ActionType::LOG_THREAD_ID:
            throw "Not Implemented."; // TODO Implement This.
            break;

         case FormatAction::ActionType::LOG_PROCESS_ID:
            throw "Not Implemented."; // TODO Implement This.
            break;

         case FormatAction::ActionType::DATE_COMPILE_ERROR:
            a_ReturnText = std::move( std::format( "?%{}?", m_FormatChar ) );
            break;

         case FormatAction::ActionType::LOGGER_COMPILE_ERROR:
            a_ReturnText = std::move( std::format( "?&{}?", m_FormatChar ) );
            break;

         default:
            throw; // TODO Exception Unknown FormatAction::ActionType
      }
   }
#pragma endregion

   /*****   SETTERS   *****/
   void Logger::SetParameters( LoggerParameters&& a_Parameters )
   {
      CompileFormat( a_Parameters.m_FormatString );
      m_Parameters = std::move( a_Parameters );
   }

   /*****   GETTERS   *****/
   const LoggerParameters& Logger::GetParameters() const
   {
      return m_Parameters;
   }
}