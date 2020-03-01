#pragma once

#include "IFormattable.h"

namespace Composing::Formattables
{
   class FChar : public IFormattable
   {
      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      const char& m_Char;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      FChar( const char& a_Char );

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual std::string ToString() const;
      virtual std::string ToString( const char*& a_FormatString ) const;
   };
}