#pragma once

#include "../SquareFlare/Core.h"

namespace Utils
{
   class StringExtract
   {
      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      const char* m_ExtractStart;
      const char* m_ExtractEnd;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      StringExtract( const char* a_ExtractStart, const char* a_ExtractEnd );
      StringExtract( const char* a_ExtractStart, PTRSIZE & a_Length );
      ~StringExtract();

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      const char*& ExtractStart();
      const char*& ExtractEnd();
      const PTRSIZE Length() const;
   };
}
