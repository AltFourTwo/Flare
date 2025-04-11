#pragma once

#ifdef FLARE_FOR_WINDOWS
   
#else
   #error Flare is windows only!
#endif

#define FLARE_BIND_EVENT_FN(x_Func) std::bind(&x_Func, this, std::placeholders::_1)
