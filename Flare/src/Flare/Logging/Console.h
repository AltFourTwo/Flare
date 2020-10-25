#pragma once

#include "Logging.h"
#include "Logger.h"
#include "LoggerParameters.h"
#include "Composing/Formattable.h"

namespace Flare
{
   class Console
   {
      using SharedLogger = Flare::Logging::Logger::SharedLogger;

      /*****   CLASS   CONSTANTS    *****/
      private:
      static const int MAX_EXTRA_LOGGERS = 16; // TWEAK/CONFIG
      static Console* s_Instance;

      /*****   CLASS   VARIABLES    *****/
      private:
      SharedLogger m_CoreLogger;
      SharedLogger m_ClientLogger;
      std::vector<SharedLogger> m_ExtraLoggers;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Console();
      Console( const Console& ) = delete;

      /*****   CLASS   FUNCTIONS    *****/
      public:
      inline static const Console& GetInstance() { return *s_Instance; }
      inline const SharedLogger& GetCoreLogger() const { return m_CoreLogger; }
      inline const SharedLogger& GetClientLogger() const { return m_ClientLogger; }
      static SharedLogger& CreateLogger( const Logging::LoggerParameters& a_Parameters ) noexcept;
      static SharedLogger& CreateLogger( Logging::LoggerParameters&& a_Parameters ) noexcept;

      /*****   CLASS   OPERATORS    *****/
      void operator=( const Console& ) = delete;
   };
}

#define FLARE_CORE_TRACE(...) (*::Flare::Console::GetInstance().GetCoreLogger()).Trace(__VA_ARGS__)
#define FLARE_CORE_INFO(...)  (*::Flare::Console::GetInstance().GetCoreLogger()).Info(__VA_ARGS__)
#define FLARE_CORE_WARN(...)  (*::Flare::Console::GetInstance().GetCoreLogger()).Warn(__VA_ARGS__)
#define FLARE_CORE_ERROR(...) (*::Flare::Console::GetInstance().GetCoreLogger()).Error(__VA_ARGS__)
#define FLARE_CORE_FATAL(...) (*::Flare::Console::GetInstance().GetCoreLogger()).Fatal(__VA_ARGS__)

#define FLARE_TRACE(...) (*::Flare::Console::GetInstance().GetClientLogger()).Trace(__VA_ARGS__)
#define FLARE_INFO(...)  (*::Flare::Console::GetInstance().GetClientLogger()).Info(__VA_ARGS__)
#define FLARE_WARN(...)  (*::Flare::Console::GetInstance().GetClientLogger()).Warn(__VA_ARGS__)
#define FLARE_ERROR(...) (*::Flare::Console::GetInstance().GetClientLogger()).Error(__VA_ARGS__)
#define FLARE_FATAL(...) (*::Flare::Console::GetInstance().GetClientLogger()).Fatal(__VA_ARGS__)