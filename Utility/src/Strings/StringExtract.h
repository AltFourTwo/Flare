#pragma once

namespace Utility::Strings
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
      StringExtract( const char* a_ExtractStart, size_t & a_Length );
      ~StringExtract();

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      const char* const& ExtractStart() const;
      const char* const& ExtractEnd() const;
      const size_t Length() const;
   };
}
