#pragma once

#ifdef SQFL_FOR_WINDOWS
   #ifdef SQFL_DLL
      #define SQFL_API __declspec(dllexport)
   #else
      #define SQFL_API __declspec(dllimport)
   #endif
#else
   #error SquareFlare is windows only!
#endif