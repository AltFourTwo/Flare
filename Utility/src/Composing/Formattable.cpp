#include "UtilityPCH.h"

#include <string>

#include "Formattable.h"
#include "Formattables/IFormattable.h"
#include "Formattables/FBoolean.h"
#include "Formattables/FChar.h"
#include "Formattables/FInteger.h"
#include "Formattables/FFloatingPoint.h"
#include "Formattables/FString.h"

namespace Utility::Composing
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   Formattable::Formattable( const bool& a_Bool )
   {
      m_Data = new Formattables::FBoolean( a_Bool );
   }

   Formattable::Formattable( const char& a_Char )
   {
      m_Data = new Formattables::FChar( a_Char );
   }

   Formattable::Formattable( const int& a_Int )
   {
      m_Data = new Formattables::FInteger( a_Int );
   }

   Formattable::Formattable( const double& a_FloatingPoint )
   {
      m_Data = new Formattables::FFloatingPoint( a_FloatingPoint );
   }

   Formattable::Formattable( const std::string& a_String )
   {
      m_Data = new Formattables::FString( a_String );
   }

   Formattable::Formattable( IFormattable& a_IFormattable ) :
      m_Data( &a_IFormattable ),
      m_CustomType( true )
   {}

   Formattable::~Formattable()
   {
      if ( !m_CustomType )
         delete m_Data;
   }

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   std::string Formattable::ToString() const
   {
      return m_Data->ToString();
   }

   std::string Formattable::ToString( const char*& a_FormatString ) const
   {
      return m_Data->ToString( a_FormatString );
   }
}