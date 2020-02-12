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

#ifdef SQFL_X64
   #define PTRSIZE uint64_t
#else
   #define PTRSIZE uint32_t
#endif