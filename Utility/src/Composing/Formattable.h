#pragma once

#include "Formattables/IFormattable.h"

namespace Utility::Composing
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
      Formattable( const bool& a_Bool );
      Formattable( const char& a_Char );
      Formattable( const int& a_Int );
      Formattable( const double& a_FloatingPoint );
      Formattable( const std::string& a_String );
      Formattable( IFormattable& a_IFormattable );
      ~Formattable();

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      std::string ToString() const;
      std::string ToString( const char*& a_FormatString ) const;
   };
}