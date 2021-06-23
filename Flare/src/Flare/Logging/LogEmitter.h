#pragma once

#include "Flare/Core.h"
#include "Console.h"

namespace Flare::Logging
{
   class LogEmitter
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      const Console::SharedLogger& m_Logger;

      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      LogEmitter( const char* a_LoggerName = Logger::DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = Logger::DEFAULT_LOG_LEVEL, const char* a_FormatString = Logger::DEFAULT_FORMAT ) noexcept;
      LogEmitter( const std::string& a_LoggerName = Logger::DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = Logger::DEFAULT_LOG_LEVEL, const std::string& a_FormatString = Logger::DEFAULT_FORMAT ) noexcept;
      LogEmitter( const std::string& a_LoggerName = Logger::DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = Logger::DEFAULT_LOG_LEVEL, std::string&& a_FormatString = Logger::DEFAULT_FORMAT ) noexcept;
      LogEmitter( std::string&& a_LoggerName = Logger::DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = Logger::DEFAULT_LOG_LEVEL, const std::string& a_FormatString = Logger::DEFAULT_FORMAT ) noexcept;
      LogEmitter( std::string&& a_LoggerName = Logger::DEFAULT_LOGGER_NAME, const LogLevel a_BaseLoggingLevel = Logger::DEFAULT_LOG_LEVEL, std::string&& a_FormatString = Logger::DEFAULT_FORMAT ) noexcept;

      LogEmitter( const LogEmitter& a_Other ) noexcept;

      /*****   CLASS   OPERATORS    *****/
      public:
      void operator=( const LogEmitter& ) = delete;

      /*****   GETTERS   *****/
      public:
      inline const Console::SharedLogger& GetLogger() const { return m_Logger; }
   };
}

#define LOG_TRACE(...) (*this->m_Logger).Trace(__VA_ARGS__)
#define LOG_INFO(...)  (*this->m_Logger).Info(__VA_ARGS__)
#define LOG_WARN(...)  (*this->m_Logger).Warn(__VA_ARGS__)
#define LOG_ERROR(...) (*this->m_Logger).Error(__VA_ARGS__)
#define LOG_FATAL(...) (*this->m_Logger).Fatal(__VA_ARGS__)
