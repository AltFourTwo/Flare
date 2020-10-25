#pragma once

#ifdef FLARE_FOR_WINDOWS
   #if FLARE_DYNAMIC_LINKING
      #ifdef FLARE_DLL
         #define FLARE_API __declspec(dllexport)
      #else
         #define FLARE_API __declspec(dllimport)
      #endif
   #else
      #define FLARE_API
   #endif
#else
   #error Flare is windows only!
#endif

#ifdef FLARE_DEBUG
   #define FLARE_ENABLE_ASSERTS true
#endif

#if FLARE_ENABLE_ASSERTS
   #define FLARE_ASSERT(x, ...) { if(!(x)) { (*::Flare::Console::GetInstance().GetClientLogger()).Error( "Assertion Failed: {0}.", __VA_ARGS__ ); __debugbreak(); } }
   #define FLARE_CORE_ASSERT(x, ...) { if(!(x)) { (*::Flare::Console::GetInstance().GetCoreLogger()).Error( "Assertion Failed: {0}.", __VA_ARGS__ ); __debugbreak(); } }
#else
   #define FLARE_ASSERT(x, ...)
   #define FLARE_CORE_ASSERT(x, ...)
#endif

#define FLARE_BIND_EVENT_FN(x_Func) std::bind(&x_Func, this, std::placeholders::_1)