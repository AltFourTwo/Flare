#pragma once

#include "Core.h"

#include <chrono>
#include <memory>

#include <spdlog/spdlog.h>

namespace Flare
{
   class Log
   {
      /*****   VARIABLES   *****/
      private:
      static std::shared_ptr<spdlog::logger> s_CoreLogger;
      static std::shared_ptr<spdlog::logger> s_ClientLogger;

      /*****   C-TOR D-TOR   *****/
      public:
      Log();
      ~Log();

      /*****   FUNCTIONS   *****/
      static void Init();

      /*****   GETTERS   *****/
      inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
      inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
   };
}

#define FLARE_CORE_TRACE(...) ::Flare::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FLARE_CORE_INFO(...)  ::Flare::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FLARE_CORE_WARN(...)  ::Flare::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FLARE_CORE_ERROR(...) ::Flare::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FLARE_CORE_FATAL(...) ::Flare::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define FLARE_TRACE(...) ::Flare::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FLARE_INFO(...)  ::Flare::Log::GetClientLogger()->info(__VA_ARGS__)
#define FLARE_WARN(...)  ::Flare::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FLARE_ERROR(...) ::Flare::Log::GetClientLogger()->error(__VA_ARGS__)
#define FLARE_FATAL(...) ::Flare::Log::GetClientLogger()->critical(__VA_ARGS__)
