#pragma once

namespace Utility::Numbers
{
   const char DIGITS[] =
   {
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',  // 0~9
      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',  // 10~19
      'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',  // 20~29
      'U', 'V', 'W', 'X', 'Y', 'Z'                       // 30~35
   };

   const char NEGATIVE = '-';

   int ConvertTwoCharsToInt( const char& a_Char1, const char& a_Char2 );
   std::string ConvertToBase( int& a_Base, const int64_t& a_IntegralValue );
}