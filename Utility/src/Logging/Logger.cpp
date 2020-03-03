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
      m_LoggingFormat( a_LoggingFormat )
   {
      // This->Log("Logger Created!");
   }

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
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

   /*********************************\
   \*****   PRIVATE-FUNCTIONS   *****/
   void Logger::Log( const char*& a_Message, std::initializer_list<Composing::Formattable> a_Formattables )
   {
      Console::Get().Log( *this, a_Message, a_Formattables );
   }
}
