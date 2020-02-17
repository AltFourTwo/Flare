#pragma once

#include "Formattable.h"
#include "IFormattable.h"
#include "Formattables/FInteger.h"

namespace Compose
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   Formattable::Formattable( int& a_Int )
   {
      m_Data = new Formattables::FInteger( a_Int );
   }

   Formattable::Formattable( IFormattable& a_IFormattable ) :
      m_Data( &a_IFormattable ),
      m_CustomType( true)
   {}

   Formattable::~Formattable()
   {
      if ( !m_CustomType )
         delete m_Data;
   }

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   const char* Formattable::ToString() const
   {
      //if ( typeisint )
      //   return (*(( Formattables::FInteger* )&m_Data)).ToString();
      return m_Data->ToString();
   }

   const char* Formattable::ToString( const char*& a_FormatString ) const
   {
      return m_Data->ToString( a_FormatString );
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