#pragma once

#include "Utils/StringExtract.h"
#include "Comp.h"
#include "../SquareFlare/Core.h"

namespace Compose
{
   class Formatter
   {
      /******************************\
      \*****   PUBLIC-MEMBERS   *****/
      public:
      Utils::StringExtract* m_Index;
      Utils::StringExtract* m_Alignment;
      Utils::StringExtract* m_Format;

      /**************************************\
      \*****   CONSTRUCTOR-DESTRUCTOR   *****/
      public:
      Formatter::Formatter( const Utils::StringExtract& a_FormatString );
      ~Formatter();




   };

}
