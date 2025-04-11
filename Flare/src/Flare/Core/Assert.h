#pragma once

#ifdef FLARE_DEBUG
   #define FLARE_ENABLE_ASSERTS true
#endif

#if FLARE_ENABLE_ASSERTS
   #include "Flare/Core/Log.h"
   #define FLARE_ASSERT(x, ...) { if(!(x)) { ::Flare::Log::GetClientLogger()->error("Assertion Failed: {0}.", __VA_ARGS__ ); __debugbreak(); } }
   #define FLARE_CORE_ASSERT(x, ...) { if(!(x)) { ::Flare::Log::GetCoreLogger()->error( "Assertion Failed: {0}.", __VA_ARGS__ ); __debugbreak(); } }
#else
   #define FLARE_ASSERT(x, ...)
   #define FLARE_CORE_ASSERT(x, ...)
#endif
