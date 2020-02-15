#pragma once

#include "SquareFlare/Core.h"

namespace Compose
{
   class SQFL_API IFormattable
   {
      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual const char* ToString() = 0;
      virtual const char* ToString( char*& const a_FormatString ) = 0;
   };
}