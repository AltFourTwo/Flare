#pragma once

namespace Utility::Compilation
{
   constexpr static const size_t ConstStrLen( const char* a_Name )
   {
      size_t x_Size = 0;

      while ( a_Name[x_Size] != 0 )
         x_Size++;

      return x_Size;
   }
}