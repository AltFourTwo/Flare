#include "UtilityPCH.h"
#include "StringUtils.h"

namespace Utility::Strings
{
   // Non-Unicode case insensitivity comparison.
   bool EqualsCaseInsensitive( const std::string& a_String1, const std::string& a_String2 )
   {
      if ( &a_String1 == &a_String2 )
         return true;

      if ( a_String1.size() != a_String2.size() )
         return false;

      return std::equal( a_String1.begin(), a_String1.end(),
                         a_String2.begin(), a_String2.end(),
                         []( char a, char b )
                         {
                            return tolower( static_cast<unsigned char>( a ) ) == tolower( static_cast<unsigned char>( b ) );
                         } );
   }
}
