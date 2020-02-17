#pragma once

#include "Formattable.h"
#include "IFormattable.h"
#include "Formattables/FInteger.h"

namespace Compose
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   Formattable::Formattable( int& a_Int ) :
      m_Data( Formattables::FInteger( a_Int ) )
   {}

   Formattable::Formattable( IFormattable& a_IFormattable ) :
      m_Data( a_IFormattable )
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   const char* Formattable::ToString() const
   {
      return m_Data.ToString();
   }

   const char* Formattable::ToString( const char*& a_FormatString ) const
   {
      return m_Data.ToString( a_FormatString );
   }

   /**********************\
   \*****   NESTED   *****/
   /*
   template<typename T>
   const char* ToString( T& a_Value )
   {
      return (char*)a_Value;
   }
   */
}