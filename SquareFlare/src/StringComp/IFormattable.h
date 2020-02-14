#pragma once

#include "SquareFlare/Core.h"

namespace Compose
{
   class SQFL_API IFormattable
   {
      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual const char* FormatToString( const char* a_FormatString ) = 0;
   };
}