#pragma once

#include "Logging.h"
#include "Logger.h"

namespace Flare::Logging
{
   class Console
   {
      public:
      using SharedLogger = std::shared_ptr<Logger>;

      /*****   CONSTANTS   *****/
      private:
      static const int MAX_EXTRA_LOGGERS = 16; // TWEAK/CONFIG
      static Console* s_Instance;

      /*****   VARIABLES   *****/
      private:
      SharedLogger m_CoreLogger;
      SharedLogger m_ClientLogger;
      std::vector<SharedLogger> m_ExtraLoggers;

      /*****  C-TOR D-TOR  *****/
      public:
      Console();
      Console( const Console& ) = delete;

      /*****   FUNCTIONS   *****/
      public:
      static SharedLogger& CreateLogger( const char* a_LoggerName = Logger::DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = Logger::DEFAULT_LOG_LEVEL, const char* a_FormatString = Logger::DEFAULT_FORMAT ) noexcept;
      static SharedLogger& CreateLogger( const std::string& a_LoggerName = Logger::DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = Logger::DEFAULT_LOG_LEVEL, const std::string& a_FormatString = Logger::DEFAULT_FORMAT ) noexcept;
      static SharedLogger& CreateLogger( const std::string& a_LoggerName = Logger::DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = Logger::DEFAULT_LOG_LEVEL, std::string&& a_FormatString = Logger::DEFAULT_FORMAT ) noexcept;
      static SharedLogger& CreateLogger( std::string&& a_LoggerName = Logger::DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = Logger::DEFAULT_LOG_LEVEL, const std::string& a_FormatString = Logger::DEFAULT_FORMAT ) noexcept;
      static SharedLogger& CreateLogger( std::string&& a_LoggerName = Logger::DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = Logger::DEFAULT_LOG_LEVEL, std::string&& a_FormatString = Logger::DEFAULT_FORMAT ) noexcept;

      /*****   OPERATORS    *****/
      void operator=( const Console& ) = delete;

      /*****   GETTERS   *****/
      inline static const Console& GetInstance() { return *s_Instance; }
      inline const SharedLogger& GetCoreLogger() const { return m_CoreLogger; }
      inline const SharedLogger& GetClientLogger() const { return m_ClientLogger; }
   };
}

#define FLARE_CORE_TRACE(...) (*::Flare::Logging::Console::GetInstance().GetCoreLogger()).Trace(__VA_ARGS__)
#define FLARE_CORE_INFO(...)  (*::Flare::Logging::Console::GetInstance().GetCoreLogger()).Info(__VA_ARGS__)
#define FLARE_CORE_WARN(...)  (*::Flare::Logging::Console::GetInstance().GetCoreLogger()).Warn(__VA_ARGS__)
#define FLARE_CORE_ERROR(...) (*::Flare::Logging::Console::GetInstance().GetCoreLogger()).Error(__VA_ARGS__)
#define FLARE_CORE_FATAL(...) (*::Flare::Logging::Console::GetInstance().GetCoreLogger()).Fatal(__VA_ARGS__)

#define FLARE_TRACE(...) (*::Flare::Logging::Console::GetInstance().GetClientLogger()).Trace(__VA_ARGS__)
#define FLARE_INFO(...)  (*::Flare::Logging::Console::GetInstance().GetClientLogger()).Info(__VA_ARGS__)
#define FLARE_WARN(...)  (*::Flare::Logging::Console::GetInstance().GetClientLogger()).Warn(__VA_ARGS__)
#define FLARE_ERROR(...) (*::Flare::Logging::Console::GetInstance().GetClientLogger()).Error(__VA_ARGS__)
#define FLARE_FATAL(...) (*::Flare::Logging::Console::GetInstance().GetClientLogger()).Fatal(__VA_ARGS__)