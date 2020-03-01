#pragma once

namespace Composing
{
   class IFormattable
   {
      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual std::string ToString() const = 0;
      virtual std::string ToString( const char*& a_FormatString ) const = 0;
   };
}