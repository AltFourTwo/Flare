#include "FFloatingPoint.h"

namespace Composing::Formattables
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   FFloatingPoint::FFloatingPoint( const double& a_Double ) :
      m_Double( a_Double )
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   std::string FFloatingPoint::ToString() const
   {
      return std::to_string( m_Double );
   }

   std::string FFloatingPoint::ToString( const char*& a_FormatString ) const
   {
      return "123.456";
   }
}
