
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
   const char* FInteger::ToString() const
   {
      return Compose::ToString( m_Int );
   }

   const char* FInteger::ToString( const char*& a_FormatString ) const
   {
      return "Format This Integer Please : " + m_Int;
   }
}