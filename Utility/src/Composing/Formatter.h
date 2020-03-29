#pragma once

#include "Strings/StringExtract.h"

namespace Composing
{
   class Formatter
   {
      /***************************\
      \*****   ENUMERATORS   *****/
      private:
      enum class StringFormatSection
      {
         INDEX = 1,
         ALIGNMENT = 2,
         FORMAT = 3
      };

      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      int m_Index;
      int m_Alignment;
      bool m_Aligned = false;
      bool m_Formatted = false;
      Utility::Strings::StringExtract m_WholeString;
      Utility::Strings::StringExtract m_IndexExtract;
      Utility::Strings::StringExtract m_AlignmentExtract;
      Utility::Strings::StringExtract m_FormatExtract;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      Formatter( Utility::Strings::StringExtract& a_FormatString );
      ~Formatter();

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      std::string FormatObject( const Formattable& a_Object ) const;

      /*********************************\
      \*****   PRIVATE-FUNCTIONS   *****/
      private:
      void ParseIndexExtract();
      void ParseAlignmentExtract();

      /***********************\
      \*****   GETTERS   *****/
      public:
      const int& Index() const
      {
         return m_Index;
      }

      const int& Alignment() const
      {
         return m_Alignment;
      }

      const bool& IsAligned() const
      {
         return m_Aligned;
      }

      const bool& IsFormatted() const
      {
         return m_Formatted;
      }
   };
}
