#pragma once

#ifdef FLARE_FOR_WINDOWS
   #ifdef FLARE_DLL
      #define FLARE_API __declspec(dllexport)
   #else
      #define FLARE_API __declspec(dllimport)
   #endif
#else
   #error Flare is windows only!
#endif

#ifdef FLARE_ENABLE_ASSERTS
   #define FLARE_ASSERT(x) { if(!(x)) { __debugbreak(); } }
   #define FLARE_CORE_ASSERT(x) { if(!(x)) { __debugbreak(); } }
#else
   #define FLARE_ASSERT(x)
   #define FLARE_CORE_ASSERT(x)
#endif