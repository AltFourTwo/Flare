#include "UtilityPCH.h"

#include "Logger.h"
#include "Console.h"

namespace Logging
{
   /**********************\
   \*****   NESTED   *****/
   Logger::FormatAction::FormatAction( const FormatAction::ReturnType& a_ReturnType, const char& a_FormatChar ) :
      m_FormatChar(a_FormatChar),
      m_ReturnType(a_ReturnType),
      m_ReturnText()
   {
      m_ReturnText.reserve( 25 );
   }

   Logger::FormatAction::FormatAction( const std::string& a_Text ) :
      m_FormatChar( 0 ),
      m_ReturnType( JUST_TEXT ),
      m_ReturnText( a_Text )
   {}

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

   void Logger::CompileFormat( std::queue<FormatAction, class queue>& a_ExecutionQueue, const std::string& a_FormatString )
   {
      a_ExecutionQueue.empty();

      // TODO Finish Implementing This

      /* Examples */
      a_ExecutionQueue.emplace( FormatAction::ReturnType::FORMATTED_DATE, '!' );
      a_ExecutionQueue.emplace( FormatAction::ReturnType::LOGGER_INFO, '!' );
      a_ExecutionQueue.emplace( "Oh no!" );
   }
}
