#pragma once

#include "Flare/Core.h"
#include "Logger.h"
#include "LoggerParameters.h"

namespace Flare::Logging
{
   class FLARE_API LogEmitter
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

   #ifdef FLARE_DLL
      #define FLARE_CORE_TRACE(...) this->LogEmitter::m_Logger->Trace(__VA_ARGS__)
      #define FLARE_CORE_INFO(...)  this->LogEmitter::m_Logger->Info(__VA_ARGS__)
      #define FLARE_CORE_WARN(...)  this->LogEmitter::m_Logger->Warn(__VA_ARGS__)
      #define FLARE_CORE_ERROR(...) this->LogEmitter::m_Logger->Error(__VA_ARGS__)
      #define FLARE_CORE_FATAL(...) this->LogEmitter::m_Logger->Fatal(__VA_ARGS__)
   #else
      #define FLARE_TRACE(...) this->LogEmitter::m_Logger->Trace(__VA_ARGS__)
      #define FLARE_INFO(...)  this->LogEmitter::m_Logger->Info(__VA_ARGS__)
      #define FLARE_WARN(...)  this->LogEmitter::m_Logger->Warn(__VA_ARGS__)
      #define FLARE_ERROR(...) this->LogEmitter::m_Logger->Error(__VA_ARGS__)
      #define FLARE_FATAL(...) this->LogEmitter::m_Logger->Fatal(__VA_ARGS__)
   #endif
   };
}