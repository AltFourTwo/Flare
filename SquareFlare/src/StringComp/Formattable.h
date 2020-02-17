#pragma once

#include "SquareFlare/Core.h"
#include "IFormattable.h"

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
      Formattable( int& a_Int );
      Formattable( IFormattable& a_IFormattable );

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      const char* ToString() const;
      const char* ToString( const char*& a_FormatString) const;
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