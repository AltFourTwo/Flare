#include "StringExtract.h"

namespace Utils
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/

   StringExtract::StringExtract() :
      m_ExtractStart(0),
      m_Length(0)
   {

   }


   StringExtract::StringExtract(char* a_ExtractStart, long long a_Length ) : 
      m_ExtractStart(a_ExtractStart),
      m_Length(a_Length)
   {

   }

   StringExtract::~StringExtract()
   {}


   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   const char* StringExtract::ViewExtract()
   {
      return "ViewExtract";
   }
}
