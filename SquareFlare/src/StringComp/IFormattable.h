#pragma once

#include <string>

#include "SquareFlare/Core.h"

namespace Compose
{
   class SQFL_API IFormattable
   {
      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual std::string ToString() const = 0;
      virtual std::string ToString( const char*& a_FormatString ) const = 0;
   };
}