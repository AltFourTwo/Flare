#include "UtilityPCH.h"

#include <string>

#include "FFloatingPoint.h"

namespace Utility::Composing::Formattables
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   FFloatingPoint::FFloatingPoint( const double& a_FloatingPoint ) :
      m_FloatingPoint( a_FloatingPoint )
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   std::string FFloatingPoint::ToString() const
   {
      return std::to_string( m_FloatingPoint );
   }

   std::string FFloatingPoint::ToString( const char*& a_FormatString ) const
   {
      // TODO Finish implementing this.
      return "123.456";
   }
}
