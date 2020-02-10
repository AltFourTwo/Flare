#pragma once

#include "SquareFlare/Core.h"

namespace Compose
{
   class SQFL_API IFormattable
   {
      virtual const char* Format( const char* a_FormatString ) = 0;
   };
}