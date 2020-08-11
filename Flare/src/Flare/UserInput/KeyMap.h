#pragma once

#include <iostream>

namespace Flare::UserInput
{
   class KeyMap
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      static const int s_KeyCodes[256]; // TWEAK : Array size is not final.

      /*****   CLASS   OPERATORS    *****/
      public:
      const int& operator[] ( const int a_Index ) const
      {
         return s_KeyCodes[a_Index];
      }
   };
}