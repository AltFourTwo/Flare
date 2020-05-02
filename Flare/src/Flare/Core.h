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