#pragma once

#include <string>

#include "SquareFlare/Core.h"
#include "Composition.h"
#include "Utils/StringExtract.h"
#include "Formattable.h"

namespace Compose
{
   class Formatter
   {
      /***************************\
      \*****   ENUMERATORS   *****/
      private:
      enum StringFormatSection
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
      Utils::StringExtract* m_WholeString;
      Utils::StringExtract* m_IndexExtract;
      Utils::StringExtract* m_AlignmentExtract;
      Utils::StringExtract* m_FormatExtract;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      Formatter( Utils::StringExtract& a_FormatString );
      ~Formatter();

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      std::string FormatObject( const Formattable& a_Object );

      /*********************************\
      \*****   PRIVATE-FUNCTIONS   *****/
      private:
      void ParseIndexExtract();
      void ParseAlignmentExtract();

      /***********************\
      \*****   GETTERS   *****/
      public:
      const int& Index()
      {
         return m_Index;
      }

      const int& Alignment()
      {
         return m_Alignment;
      }

      const bool& IsAligned()
      {
         return m_Aligned;
      }

      const bool& IsFormatted()
      {
         return m_Formatted;
      }
   };
}
