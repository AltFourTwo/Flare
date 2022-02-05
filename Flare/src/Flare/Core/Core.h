#pragma once

#ifdef FLARE_FOR_WINDOWS
   
#else
   #error Flare is windows only!
#endif

#ifdef FLARE_DEBUG
   #define FLARE_ENABLE_ASSERTS true
#endif

#if FLARE_ENABLE_ASSERTS
   #include "Flare/Logging/LogService.h"
   #define FLARE_ASSERT(x, ...) { if(!(x)) { (*::Flare::Logging::LogService::GetInstance().GetClientLogger()).Error( "Assertion Failed: {0}.", __VA_ARGS__ ); __debugbreak(); } }
   #define FLARE_CORE_ASSERT(x, ...) { if(!(x)) { (*::Flare::Logging::LogService::GetInstance().GetCoreLogger()).Error( "Assertion Failed: {0}.", __VA_ARGS__ ); __debugbreak(); } }
#else
   #define FLARE_ASSERT(x, ...)
   #define FLARE_CORE_ASSERT(x, ...)
#endif

#define FLARE_BIND_EVENT_FN(x_Func) std::bind(&x_Func, this, std::placeholders::_1)
