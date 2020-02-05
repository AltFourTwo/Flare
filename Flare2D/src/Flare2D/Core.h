#pragma once

#ifdef F2D_FOR_WINDOWS
   #ifdef F2D_DLL
      #define F2D_API __declspec(dllexport)
   #else
      #define F2D_API __declspec(dllimport)
   #endif
#else
   #error Flare2D is windows only!
#endif