#pragma once

#include "Logger.h"
#include "LoggerParameters.h"

namespace Flare::Logging
{
   class LogEmitter
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      Logger::SharedLogger& m_Logger;

      /*****   CLASS   C-TOR D-TOR  *****/
      LogEmitter( const LoggerParameters& a_Parameters ) noexcept;
      LogEmitter( LoggerParameters&& a_Parameters ) noexcept;
      LogEmitter( const LogEmitter& a_Other ) noexcept;

      /*****   CLASS   OPERATORS    *****/
      public:
      void operator=( const LogEmitter& ) = delete;

   #define FLARE_CORE_TRACE(...) this->m_Logger->Trace(__VA_ARGS__)
   #define FLARE_CORE_INFO(...)  this->m_Logger->Info(__VA_ARGS__)
   #define FLARE_CORE_WARN(...)  this->m_Logger->Warn(__VA_ARGS__)
   #define FLARE_CORE_ERROR(...) this->m_Logger->Error(__VA_ARGS__)
   #define FLARE_CORE_FATAL(...) this->m_Logger->Fatal(__VA_ARGS__)
   };
}