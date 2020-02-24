#pragma once

#include <string>

#include "Formattables/IFormattable.h"

namespace Composing
{
   class Formattable : public IFormattable
   {
      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      IFormattable* m_Data;
      bool m_CustomType = false;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      Formattable( int& a_Int );
      Formattable( IFormattable& a_IFormattable );
      ~Formattable();

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      std::string ToString() const;
      std::string ToString( const char*& a_FormatString ) const;
   };
}