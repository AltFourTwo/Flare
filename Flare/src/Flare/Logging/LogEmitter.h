#pragma once

#include "Flare/Core.h"
#include "Logger.h"
#include "LoggerParameters.h"

namespace Flare::Logging
{
   class LogEmitterBase
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      const Logger::SharedLogger& m_Logger;

      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      LogEmitterBase( const LoggerParameters& a_Parameters ) noexcept;
      LogEmitterBase( LoggerParameters&& a_Parameters ) noexcept;
      LogEmitterBase( const LogEmitterBase& a_Other ) noexcept;

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual inline const Logger::SharedLogger& GetLogger() const { return GetLogger_I(); };

      protected:
      virtual inline const Logger::SharedLogger& GetLogger_I() const = 0;

      /*****   CLASS   OPERATORS    *****/
      public:
      void operator=( const LogEmitterBase& ) = delete;
   };

   class CoreLogEmitter : public LogEmitterBase
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      CoreLogEmitter( const LoggerParameters& a_Parameters ) noexcept;
      CoreLogEmitter( LoggerParameters&& a_Parameters ) noexcept;
      CoreLogEmitter( const CoreLogEmitter& a_Other ) noexcept;

      /*****   CLASS   FUNCTIONS    *****/
      protected:
      virtual inline const Logger::SharedLogger& GetLogger_I() const { return m_Logger; }

      /*****   CLASS   OPERATORS    *****/
      public:
      void operator=( const CoreLogEmitter& ) = delete;
   };

   class FLARE_API LogEmitter : public LogEmitterBase
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      LogEmitter( const LoggerParameters& a_Parameters ) noexcept;
      LogEmitter( LoggerParameters&& a_Parameters ) noexcept;
      LogEmitter( const LogEmitter& a_Other ) noexcept;

      /*****   CLASS   FUNCTIONS    *****/
      protected:
      virtual inline const Logger::SharedLogger& GetLogger_I() const { return m_Logger; }

      /*****   CLASS   OPERATORS    *****/
      public:
      void operator=( const LogEmitter& ) = delete;
   };

   #ifdef FLARE_DLL
      #define FLARE_CORE_TRACE(...) this->GetLogger()->Trace(__VA_ARGS__)
      #define FLARE_CORE_INFO(...)  this->GetLogger()->Info(__VA_ARGS__)
      #define FLARE_CORE_WARN(...)  this->GetLogger()->Warn(__VA_ARGS__)
      #define FLARE_CORE_ERROR(...) this->GetLogger()->Error(__VA_ARGS__)
      #define FLARE_CORE_FATAL(...) this->GetLogger()->Fatal(__VA_ARGS__)
   #else
      #define FLARE_TRACE(...) this->LogEmitter::GetLogger()->Trace(__VA_ARGS__)
      #define FLARE_INFO(...)  this->LogEmitter::GetLogger()->Info(__VA_ARGS__)
      #define FLARE_WARN(...)  this->LogEmitter::GetLogger()->Warn(__VA_ARGS__)
      #define FLARE_ERROR(...) this->LogEmitter::GetLogger()->Error(__VA_ARGS__)
      #define FLARE_FATAL(...) this->LogEmitter::GetLogger()->Fatal(__VA_ARGS__)
   #endif

   // For logging outside of a LogEmitter instance
   #define FLARE_EXT_TRACE(_ext, ...) _ext::GetInstance().GetLogger()->Trace(__VA_ARGS__)
   #define FLARE_EXT_INFO(_ext, ...)  _ext::GetInstance().GetLogger()->Info(__VA_ARGS__)
   #define FLARE_EXT_WARN(_ext, ...)  _ext::GetInstance().GetLogger()->Warn(__VA_ARGS__)
   #define FLARE_EXT_ERROR(_ext, ...) _ext::GetInstance().GetLogger()->Error(__VA_ARGS__)
   #define FLARE_EXT_FATAL(_ext, ...) _ext::GetInstance().GetLogger()->Fatal(__VA_ARGS__)
}