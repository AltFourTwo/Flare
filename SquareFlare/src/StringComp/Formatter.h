#pragma once

#include <string>

#include "Composition.h"
#include "Utils/StringExtract.h"
#include "IFormattable.h"

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

      /******************************\
      \*****   PUBLIC-MEMBERS   *****/
      public:
      int m_Index;
      int m_Alignment;
      bool m_Aligned = false;
      bool m_Formatted = false;

      /*******************************\
      \*****   PRIVATE-MEMBERS   *****/
      private:
      const Utils::StringExtract* m_IndexExtract;
      const Utils::StringExtract* m_AlignmentExtract;
      const Utils::StringExtract* m_FormatExtract;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      Formatter( const Utils::StringExtract& a_FormatString );
      ~Formatter();

      /********************************\
      \*****   PUBLIC-FUNCTIONS   *****/
      public:
      std::string FormatValue( IFormattable& a_Object );

      /*********************************\
      \*****   PRIVATE-FUNCTIONS   *****/
      private:
      void ParseIndexExtract();
      void ParseAlignmentExtract();
   };

}
