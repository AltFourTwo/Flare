#include "UtilityPCH.h"

#include "FChar.h"

namespace Composing::Formattables
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   FChar::FChar( const char& a_Char ) :
      m_Char( a_Char )
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   std::string FChar::ToString() const
   {
      return std::string( 1, m_Char );
   }

   std::string FChar::ToString( const char*& a_FormatString ) const
   {
      if ( *a_FormatString == '#' )
         return std::to_string( (int)m_Char );
      else
         return std::string( 1, m_Char );
   }
}
