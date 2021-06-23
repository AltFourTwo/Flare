#include "FlarePCH.h"
#include "Console.h"
#include "Logger.h"

#include <iostream>
#include <string>
#include <vector>

namespace Flare::Logging
{
   Console* Console::s_Instance = nullptr;

   /*****   CLASS   C-TOR D-TOR  *****/
   Console::Console() :
      m_ExtraLoggers()
   {
      FLARE_CORE_ASSERT( !s_Instance, "An instance of Flare::Console aleady exists!" ); // TODO more logs & error codes.
      s_Instance = this;

      m_ExtraLoggers.reserve( MAX_EXTRA_LOGGERS );
      m_CoreLogger = std::make_shared<Logger>( "Core", LogLevel::Trace, "[%T] &N : &M" );
      m_ClientLogger = std::make_shared<Logger>( "Client", LogLevel::Trace, "[%T] &N : &M" );
   }

   /*****   CLASS   FUNCTIONS    *****/
   Console::SharedLogger& Console::CreateLogger( const char* a_LoggerName, const LogLevel a_BaseLoggingLevel, const char* a_FormatString ) noexcept
   {
      s_Instance->m_ExtraLoggers.emplace_back( std::make_shared<Logger>( a_LoggerName, a_BaseLoggingLevel, a_FormatString ) );
      return s_Instance->m_ExtraLoggers.back();
   }

   Console::SharedLogger& Console::CreateLogger( const std::string& a_LoggerName, const LogLevel a_BaseLoggingLevel, const std::string& a_FormatString ) noexcept
   {
      s_Instance->m_ExtraLoggers.emplace_back( std::make_shared<Logger>( a_LoggerName, a_BaseLoggingLevel, a_FormatString ) );
      return s_Instance->m_ExtraLoggers.back();
   }

   Console::SharedLogger& Console::CreateLogger( const std::string& a_LoggerName, const LogLevel a_BaseLoggingLevel, std::string&& a_FormatString ) noexcept
   {
      s_Instance->m_ExtraLoggers.emplace_back( std::make_shared<Logger>( a_LoggerName, a_BaseLoggingLevel, std::move( a_FormatString ) ) );
      return s_Instance->m_ExtraLoggers.back();
   }

   Console::SharedLogger& Console::CreateLogger( std::string&& a_LoggerName, const LogLevel a_BaseLoggingLevel, const std::string& a_FormatString ) noexcept
   {
      s_Instance->m_ExtraLoggers.emplace_back( std::make_shared<Logger>( std::move( a_LoggerName ), a_BaseLoggingLevel, a_FormatString ) );
      return s_Instance->m_ExtraLoggers.back();
   }

   Console::SharedLogger& Console::CreateLogger( std::string&& a_LoggerName, const LogLevel a_BaseLoggingLevel, std::string&& a_FormatString ) noexcept
   {
      s_Instance->m_ExtraLoggers.emplace_back( std::make_shared<Logger>( std::move( a_LoggerName ), a_BaseLoggingLevel, std::move( a_FormatString ) ) );
      return s_Instance->m_ExtraLoggers.back();
   }
}