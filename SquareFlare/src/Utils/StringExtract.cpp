#include "StringExtract.h"

namespace Utils
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   /*
   StringExtract::StringExtract() :
      m_ExtractStart(0),
      m_Length(0)
   {

   }

   StringExtract::StringExtract( const StringExtract& a_SE ) :
      m_ExtractStart( 0 ),
      m_Length( 0 )
   {

   }
   */

   StringExtract::StringExtract( const char* a_ExtractStart, const char* a_ExtractEnd ) :
      m_ExtractStart( a_ExtractStart ),
      m_ExtractEnd( a_ExtractEnd )
   {

   }

   StringExtract::~StringExtract()
   {}


   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   const char* StringExtract::ExtractStart() const
   {
      return m_ExtractStart;
   }

   const char* StringExtract::ExtractEnd() const
   {
      return m_ExtractEnd;
   }

   const PTRSIZE StringExtract::Length() const
   {
      return m_ExtractEnd - m_ExtractStart;
   }
}
