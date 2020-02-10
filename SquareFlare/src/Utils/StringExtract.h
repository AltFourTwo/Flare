#pragma once

#include <string>

namespace Utils
{


   class StringExtract
   {
      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      //const std::string& m_MainString;
      char* m_ExtractStart;
      const long long m_Length;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      StringExtract();
      StringExtract(char* a_ExtractStart, long long a_Length );
      ~StringExtract();


      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      const char* ViewExtract();
   };

}
