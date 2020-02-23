
#include "NumberUtils.h"

namespace Utils::Numbers
{
   int ConvertTwoCharsToInt( const char& a_Char1, const char& a_Char2 )
   {
      int x_Result = 0;

      if ( a_Char1 >= DIGITS[0] && a_Char1 <= DIGITS[9] )
      {
         x_Result += a_Char1 - DIGITS[0];

         if ( a_Char2 >= DIGITS[0] && a_Char2 <= DIGITS[9] )
         {
            x_Result *= 10;
            x_Result += a_Char2 - DIGITS[0];
         }
      }

      return x_Result;
   }

   std::string ConvertToBase( int& a_Base, const int64_t& a_IntegralValue )
   {
      if ( a_Base == 10 )
         return std::to_string( a_IntegralValue );

      std::string x_Out;
      int x_Length = log( a_IntegralValue ) / log( a_Base );
      x_Out.append( x_Length + 1, ' ' );
      int64_t x_Remainder = 0;
      int64_t x_Dividend = a_IntegralValue;
      
      int i = x_Length;
      do
      {
         x_Remainder = x_Dividend % a_Base;
         x_Dividend /= a_Base;
         x_Out[i--] = DIGITS[x_Remainder];
      } while ( x_Dividend > 0 );

      return x_Out;
   }
}