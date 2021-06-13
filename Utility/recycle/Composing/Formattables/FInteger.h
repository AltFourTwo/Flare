#pragma once

#include "IFormattable.h"

namespace Utility::Composing::Formattables
{
   class FInteger : public IFormattable
   {
      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      const int& m_Int;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      FInteger( const int& a_Int );

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual std::string ToString() const;
      virtual std::string ToString( const char*& a_FormatString ) const;
   };
}