
#include "FInteger.h"
#include "StringComp/Formattable.h"

namespace Compose::Formattables
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   FInteger::FInteger( int& a_Int ) :
      m_Int( a_Int )
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   std::string FInteger::ToString() const
   {
      return std::to_string( m_Int );
   }

   std::string FInteger::ToString( const char*& a_FormatString ) const
   {
      std::string x_Out = "Integer : ";

      return x_Out + std::to_string( m_Int );
   }
}