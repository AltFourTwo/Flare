#pragma once

#include <string>

#include "../SquareFlare/Core.h"

namespace Utils
{


   class StringExtract
   {
      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      //const std::string& m_MainString;
      const char* m_ExtractStart;
      const char* m_ExtractEnd;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      //StringExtract( const StringExtract& a_SE );
      StringExtract( const char* a_ExtractStart, const char* a_ExtractEnd );
      ~StringExtract();


      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      const char* ExtractStart() const;
      const char* ExtractEnd() const;
      const PTRSIZE Length() const;
   };

}
