#include "FlarePCH.h"
#include "LogEmitter.h"
#include "Console.h"

namespace Flare::Logging
{
   /*****  C-TOR D-TOR  *****/
   LogEmitter::LogEmitter( const char* a_LoggerName, const LogLevel a_BaseLoggingLevel, const char* a_FormatString ) noexcept :
      m_Logger( Console::GetInstance().CreateLogger( a_LoggerName, a_BaseLoggingLevel, a_FormatString ) )
   {}

   LogEmitter::LogEmitter( const std::string& a_LoggerName, const LogLevel a_BaseLoggingLevel, const std::string& a_FormatString ) noexcept :
      m_Logger( Console::GetInstance().CreateLogger( a_LoggerName, a_BaseLoggingLevel, a_FormatString ) )
   {}

   LogEmitter::LogEmitter( const std::string& a_LoggerName, const LogLevel a_BaseLoggingLevel, std::string&& a_FormatString ) noexcept :
      m_Logger( Console::GetInstance().CreateLogger( a_LoggerName, a_BaseLoggingLevel, std::move( a_FormatString ) ) )
   {}

   LogEmitter::LogEmitter( std::string&& a_LoggerName, const LogLevel a_BaseLoggingLevel, const std::string& a_FormatString ) noexcept :
      m_Logger( Console::GetInstance().CreateLogger( std::move( a_LoggerName ), a_BaseLoggingLevel, a_FormatString ) )
   {}

   LogEmitter::LogEmitter( std::string&& a_LoggerName, const LogLevel a_BaseLoggingLevel, std::string&& a_FormatString ) noexcept :
      m_Logger( Console::GetInstance().CreateLogger( std::move( a_LoggerName ), a_BaseLoggingLevel, std::move( a_FormatString ) ) )
   {}

   LogEmitter::LogEmitter( const LogEmitter& a_Other ) noexcept :
      m_Logger( a_Other.m_Logger )
   {}
}