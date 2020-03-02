#include "UtilityPCH.h"

#include "Logger.h"

namespace Logging
{
   
   Logger::Logger( const char*& a_LoggerName = DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = Logger::TRACE, const int& a_TextColor = DEFAULT_TEXT_COLOR, const int& a_BGColor = DEFAULT_BG_COLOR, const std::string& a_LoggingFormat = Logging::DEFAULT_FORMAT) :
      m_LoggerName( a_LoggerName ),
      m_BaseLoggingLevel( a_BaseLoggingLevel ),
      m_TextColor( a_TextColor ),
      m_BGColor( a_BGColor ),
      m_LoggingFormat( a_LoggingFormat )
   {
      // This->Log("Logger Created!");
   }

   Logger::~Logger()
   {}

   void Logger::Trace( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables )
   {
      if ( m_BaseLoggingLevel >= TRACE )
         Logger::Log( a_Message, a_Formattables );
   }

   void Logger::Debug( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables )
   {
      if ( m_BaseLoggingLevel >= DEBUG )
         Logger::Log( a_Message, a_Formattables );
   }

   void Logger::Info( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables )
   {
      if ( m_BaseLoggingLevel >= INFO )
         Logger::Log( a_Message, a_Formattables );
   }

   void Logger::Warn( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables )
   {
      if ( m_BaseLoggingLevel >= WARNING )
         Logger::Log( a_Message, a_Formattables );
   }

   void Logger::Error( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables )
   {
      if ( m_BaseLoggingLevel >= ERROR )
         Logger::Log( a_Message, a_Formattables );
   }

   void Logger::Fatal( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables )
   {
      if ( m_BaseLoggingLevel >= FATAL )
         Logger::Log( a_Message, a_Formattables );
   }

   void Logger::Log( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables )
   {
      
   }
}
