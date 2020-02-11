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
      const long long m_Length;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      StringExtract( const StringExtract& a_SE );
      StringExtract( const char* a_ExtractStart, const long long a_Length );
      ~StringExtract();


      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      const char* ViewExtract() const;
   };

}
