#pragma once

#include "SquareFlare/Core.h"

namespace Compose
{
   class SQFL_API IFormattable
   {
      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual const char* ToString() const = 0;
      virtual const char* ToString( const char*& a_FormatString ) const = 0;
   };
}