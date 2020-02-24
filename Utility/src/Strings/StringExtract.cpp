#include "StringExtract.h"

namespace Utility::Strings
{
   /**************************************\
   \*****   CONSTRUCTOR-DESTRUCTOR   *****/
   StringExtract::StringExtract( const char* a_ExtractStart, const char* a_ExtractEnd ) :
      m_ExtractStart( a_ExtractStart ),
      m_ExtractEnd( a_ExtractEnd )
   {
      if ( a_ExtractStart > a_ExtractEnd )
         throw; // TODO Exception Pointers out of order. 
   }

   StringExtract::StringExtract( const char* a_ExtractStart, size_t & a_Length ) :
      m_ExtractStart( a_ExtractStart ),
      m_ExtractEnd( a_ExtractStart + a_Length )
   {
      if ( a_Length < 0 )
         throw; // TODO Exception Length cannot be negative.
   }

   StringExtract::~StringExtract()
   {}

   /********************************\
   \*****   PUBLIC-FUNCTIONS   *****/
   const char* const& StringExtract::ExtractStart() const
   {
      return m_ExtractStart;
   }

   const char* const& StringExtract::ExtractEnd() const
   {
      return m_ExtractEnd;
   }

   const size_t StringExtract::Length() const
   {
      return m_ExtractEnd - m_ExtractStart;
   }
}
