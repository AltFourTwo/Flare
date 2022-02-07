#pragma once

#include "Flare/Logging/LogService.h"

#define FLARE_CORE_TRACE(...) ::Flare::Logging::LogService::GetCoreLogger()->Trace(__VA_ARGS__)
#define FLARE_CORE_INFO(...)  ::Flare::Logging::LogService::GetCoreLogger()->Info(__VA_ARGS__)
#define FLARE_CORE_WARN(...)  ::Flare::Logging::LogService::GetCoreLogger()->Warn(__VA_ARGS__)
#define FLARE_CORE_ERROR(...) ::Flare::Logging::LogService::GetCoreLogger()->Error(__VA_ARGS__)
#define FLARE_CORE_FATAL(...) ::Flare::Logging::LogService::GetCoreLogger()->Fatal(__VA_ARGS__)

#define FLARE_TRACE(...) ::Flare::Logging::LogService::GetClientLogger()->Trace(__VA_ARGS__)
#define FLARE_INFO(...)  ::Flare::Logging::LogService::GetClientLogger()->Info(__VA_ARGS__)
#define FLARE_WARN(...)  ::Flare::Logging::LogService::GetClientLogger()->Warn(__VA_ARGS__)
#define FLARE_ERROR(...) ::Flare::Logging::LogService::GetClientLogger()->Error(__VA_ARGS__)
#define FLARE_FATAL(...) ::Flare::Logging::LogService::GetClientLogger()->Fatal(__VA_ARGS__)
