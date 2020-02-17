#pragma once

#include "SquareFlare/Core.h"
#include "IFormattable.h"
#include "Formattables/FInteger.h"

namespace Compose
{
   class Formattable : public IFormattable
   {
      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      IFormattable& m_Data;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      Formattable( int& a_Int ) :
         m_Data( Formattables::FInteger( a_Int ) )
      {}

      Formattable( IFormattable& a_IFormattable ) :
         m_Data( a_IFormattable )
      {}

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      const char* ToString() const
      {
         return m_Data.ToString();
      }

      const char* ToString( const char*& a_FormatString) const
      {
         return m_Data.ToString( a_FormatString );
      }
   };

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