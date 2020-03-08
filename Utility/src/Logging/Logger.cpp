#include "UtilityPCH.h"

#include "Logger.h"
#include "Console.h"

namespace Logging
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   Logger::Logger( const char*& a_LoggerName, const LogLevel a_BaseLoggingLevel, const int& a_TextColor, const int& a_BGColor, const std::string& a_LoggingFormat ) :
      m_LoggerName( a_LoggerName ),
      m_BaseLoggingLevel( a_BaseLoggingLevel ),
      m_TextColor( a_TextColor ),
      m_BGColor( a_BGColor ),
      m_ExecutionQueue()
   {
      CompileFormat( m_ExecutionQueue, a_LoggingFormat );
      // This->Log("Logger Created!");
   }

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   // Log Without Formattables
   void Logger::Trace( const char*& a_Message )
   {
      if ( m_BaseLoggingLevel <= TRACE )
         Logger::Log( TRACE, a_Message );
   }

   void Logger::Debug( const char*& a_Message )
   {
      if ( m_BaseLoggingLevel <= DEBUG )
         Logger::Log( DEBUG, a_Message );
   }

   void Logger::Info( const char*& a_Message )
   {
      if ( m_BaseLoggingLevel <= INFO )
         Logger::Log( INFO, a_Message );
   }

   void Logger::Warn( const char*& a_Message )
   {
      if ( m_BaseLoggingLevel <= WARNING )
         Logger::Log( WARNING, a_Message );
   }

   void Logger::Error( const char*& a_Message )
   {
      if ( m_BaseLoggingLevel <= ERROR )
         Logger::Log( ERROR, a_Message );
   }

   void Logger::Fatal( const char*& a_Message )
   {
      if ( m_BaseLoggingLevel <= FATAL )
         Logger::Log( FATAL, a_Message );
   }

   // Log With Formattables
   void Logger::Trace( const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
   {
      if ( m_BaseLoggingLevel <= TRACE )
         Logger::Log( TRACE, a_Message, a_Formattables );
   }

   void Logger::Debug( const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
   {
      if ( m_BaseLoggingLevel <= DEBUG )
         Logger::Log( DEBUG, a_Message, a_Formattables );
   }

   void Logger::Info( const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
   {
      if ( m_BaseLoggingLevel <= INFO )
         Logger::Log( INFO, a_Message, a_Formattables );
   }

   void Logger::Warn( const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
   {
      if ( m_BaseLoggingLevel <= WARNING )
         Logger::Log( WARNING, a_Message, a_Formattables );
   }

   void Logger::Error( const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
   {
      if ( m_BaseLoggingLevel <= ERROR )
         Logger::Log( ERROR, a_Message, a_Formattables );
   }

   void Logger::Fatal( const char*& a_Message, const std::initializer_list<Composing::Formattable>& a_Formattables )
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

   void Logger::SetFormat( const std::string& a_Format )
   {
      CompileFormat( m_ExecutionQueue, a_Format );
   }

   /***********************\
   \*****   GETTERS   *****/
   const std::string& Logger::GetName() const
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

   void Logger::CompileFormat( std::deque<FormatAction>& a_ExecutionQueue, const std::string& a_FormatString )
   {
      a_ExecutionQueue.empty();

      // TODO Finish Implementing This.

      /* Examples */
      a_ExecutionQueue.emplace_back( "Oh no!" ); // SIMPLE_TEXT
      a_ExecutionQueue.emplace_back( FormatAction::ActionType::FORMAT_DATE, '!' );
      a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOGGER_NAME, LCC_LOGGER_NAME );
      a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOG_LEVEL, LCC_LOG_LEVEL );
      a_ExecutionQueue.emplace_back( FormatAction::ActionType::LOG_MESSAGE, LCC_MESSAGE );
      a_ExecutionQueue.emplace_back( FormatAction::ActionType::AMPERSAND, LCC_AMPERSAND );
   }

   std::string Logger::ExecuteQueue( const LogLevel& a_LogLevel, const char*& a_Message ) const
   {
      std::string x_ConsoleMessage;
      x_ConsoleMessage.reserve( strlen( a_Message ) + 250 ); // TWEAK

      for ( FormatAction itr : m_ExecutionQueue )
      {
         x_ConsoleMessage += itr.ExecuteAction( *this, a_LogLevel, a_Message );
      }

      return x_ConsoleMessage;
   }

   /**********************\
   \*****   NESTED   *****/
   Logger::FormatAction::FormatAction( const FormatAction::ActionType& a_ActionType, const char& a_FormatChar ) :
      m_FormatChar( a_FormatChar ),
      m_ActionType( a_ActionType ),
      m_ReturnText()
   {}

   Logger::FormatAction::FormatAction( const std::string& a_Text ) :
      m_FormatChar( 0 ),
      m_ActionType( SIMPLE_TEXT ),
      m_ReturnText( a_Text )
   {}

   std::string Logger::FormatAction::ExecuteAction( const Logger& a_Logger, const LogLevel& a_LogLevel, const char*& a_Message )
   {
      switch ( m_ActionType )
      {
         case ( SIMPLE_TEXT ):
            return m_ReturnText;

         case ( FORMAT_DATE ):
         {
            char x_Buffer[40]; // TWEAK
            const char x_Format[] = { '%', m_FormatChar, 0 };
            const time_t x_RawTime = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
            struct tm * x_TimeNow = localtime( &x_RawTime );
            int x_TimeStringLength = strftime( x_Buffer, 40, x_Format, x_TimeNow ); // TWEAK

            m_ReturnText = std::string( x_Buffer, x_TimeStringLength );

            return m_ReturnText;
         }

         case ( LOGGER_NAME ):
            return a_Logger.GetName();

         case ( LOG_LEVEL ):
         {
            switch ( a_LogLevel )
            {
               case ( TRACE ):
                  return "TRACE";

               case( DEBUG ):
                  return "DEBUG";

               case( INFO ):
                  return "INFO";

               case( WARNING ):
                  return "WARNING";

               case( ERROR ):
                  return "ERROR";

               case( FATAL ):
                  return "FATAL";

               default:
                  throw; // TODO Exception Unknown Logging::LogLevel
            }
         }

         case ( LOG_MESSAGE ):
            return a_Message;

         case ( TIME_DIFFERENCE ):
            // TODO Implement This.
            break;

         case ( AMPERSAND ):
            return "%";

         default:
            throw; // TODO Exception Unknown FormatAction::ActionType
      }
   }
}
