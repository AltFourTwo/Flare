#pragma once

#include "Flare/Logging/Logger.h"

namespace Flare::Logging
{
   class LogEmitter
   {
      /*****   VARIABLES   *****/
      protected:
      const SharedLogger m_Logger;

      /*****  C-TOR D-TOR  *****/
      protected:
      LogEmitter( const char* a_LoggerName ) noexcept;
      LogEmitter( std::string&& a_LoggerName ) noexcept;

      LogEmitter( const LogEmitter& a_Other ) noexcept;

      /*****   OPERATORS    *****/
      public:
      void operator=( const LogEmitter& ) = delete;

      /*****   GETTERS   *****/
      public:
      inline const SharedLogger GetLogger() const { return m_Logger; }
   };
}

#define LOG_TRACE(...) (*this->m_Logger).Trace(__VA_ARGS__)
#define LOG_INFO(...)  (*this->m_Logger).Info(__VA_ARGS__)
#define LOG_WARN(...)  (*this->m_Logger).Warn(__VA_ARGS__)
#define LOG_ERROR(...) (*this->m_Logger).Error(__VA_ARGS__)
#define LOG_FATAL(...) (*this->m_Logger).Fatal(__VA_ARGS__)
