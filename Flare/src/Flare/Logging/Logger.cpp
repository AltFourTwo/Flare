#include "FlarePCH.h"
#include "Logger.h"

namespace Flare::Logging
{
   /*****   CONSTANTS   *****/
   const char* DEFAULT_LOGGER_NAME = "Unnamed Logger";
   const char* DEFAULT_FORMAT = "{:M}";

   /*****  C-TOR D-TOR  *****/
   Logger::Logger( const char* a_LoggerName, const LogLevel a_BaseLoggingLevel, const char* a_FormatString ) noexcept :
      m_LoggerName( a_LoggerName ),
      m_BaseLoggingLevel( a_BaseLoggingLevel ),
      m_FormatString( a_FormatString )
   {}

   Logger::Logger( const std::string& a_LoggerName, const LogLevel a_BaseLoggingLevel, const std::string& a_FormatString ) noexcept :
      m_LoggerName( a_LoggerName ),
      m_BaseLoggingLevel( a_BaseLoggingLevel ),
      m_FormatString( a_FormatString )
   {}

   Logger::Logger( const std::string& a_LoggerName, const LogLevel a_BaseLoggingLevel, std::string&& a_FormatString )  noexcept :
      m_LoggerName( a_LoggerName ),
      m_BaseLoggingLevel( a_BaseLoggingLevel ),
      m_FormatString( std::move( a_FormatString ) )
   {}

   Logger::Logger( std::string&& a_LoggerName, const LogLevel a_BaseLoggingLevel, const std::string& a_FormatString ) noexcept :
      m_LoggerName( std::move( a_LoggerName ) ),
      m_BaseLoggingLevel( a_BaseLoggingLevel ),
      m_FormatString( a_FormatString )
   {}

   Logger::Logger( std::string&& a_LoggerName, const LogLevel a_BaseLoggingLevel, std::string&& a_FormatString ) noexcept :
      m_LoggerName( std::move( a_LoggerName ) ),
      m_BaseLoggingLevel( a_BaseLoggingLevel ),
      m_FormatString( std::move( a_FormatString ) )
   {}
}