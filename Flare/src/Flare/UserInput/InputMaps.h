#pragma once

#include "InputCodes.h"

#include <initializer_list>
#include <utility>

namespace Flare::UserInput
{
   template<int size_t>
   class InputMaps
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      static const int s_InputCodes[size_t]; // TWEAK : Array size is not final.

      /*****   CLASS   OPERATORS    *****/
      public:
      const int& operator[] ( const int a_Index ) const
      {
         return s_InputCodes[a_Index];
      }
   };

   class KeyMap : public InputMaps<128>{};
   class ModifierMap : public InputMaps<6> {};
   class MouseMap : public InputMaps<8> {};
   class JoystickMap : public InputMaps<16> {};
   class GamePadMap : public InputMaps<16> {};
   class GamePadAxisMap : public InputMaps<6> {};
}