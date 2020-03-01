#pragma once

#include "IFormattable.h"

namespace Composing::Formattables
{
   class FBoolean : public IFormattable
   {
      /*************************\
      \*****   CONSTANTS   *****/
      private:
      const char* TEXT_TRUE = "True";
      const char* TEXT_FALSE = "False";
      const char* TEXT_YES = "Yes";
      const char* TEXT_NO = "No";
      const char CHAR_T = 'T';
      const char CHAR_F = 'F';
      const char CHAR_Y = 'Y';
      const char CHAR_N = 'N';
      const char CHAR_O = 'O';
      const char CHAR_X = 'X';

      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      const bool& m_Bool;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      FBoolean( const bool& a_Bool );

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      virtual std::string ToString() const;
      virtual std::string ToString( const char*& a_FormatString ) const;
   };
}