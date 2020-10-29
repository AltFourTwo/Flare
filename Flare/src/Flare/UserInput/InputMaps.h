#pragma once
#include "InputCodes.h"

#include <initializer_list>
#include <utility>

namespace Flare::UserInput
{
   /*****   NAMESPACE   CONSTANTS   *****/
   enum class InputMapType
   {
      Undefined = 0,

      Keyboard = 1,
      Modifier = 2,
      Mouse = 3,
      Joystick = 4,
      GamePad = 5,
      GamePadAxis = 6
   };

   template<InputMapType T_InputMapType, size_t T_Size>
   class InputMap
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      static const int s_InputCodes[T_Size];

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual std::string ToString() const { return GetName(); }

      /*****   CLASS   OPERATORS    *****/
      public:
      const int& operator[] ( const int a_Index ) const { return s_InputCodes[a_Index]; }

      /*****   GETTERS   *****/
      public:
      InputMapType GetStaticType() { return T_InputMapType; }
      InputMapType GetInputMapType() const { return GetStaticType(); };
      virtual const char* GetName() const = 0;
   };

   // This macro is used as quick heritance of the abstract class above.
#define FLARE_INPUT_MAP_DEF( a_ClassName, a_InputMapTypeName, a_Size ) class\
   a_ClassName : public InputMap<InputMapType::##a_InputMapTypeName, a_Size>\
   {\
      virtual const char* GetName() const override { return #a_InputMapTypeName; }\
   };\

   FLARE_INPUT_MAP_DEF( KeyMap, Keyboard, 128 );
   FLARE_INPUT_MAP_DEF( ModifierMap, Modifier, 6 );
   FLARE_INPUT_MAP_DEF( MouseMap, Mouse, 8 );
   FLARE_INPUT_MAP_DEF( JoystickMap, Joystick, 16 );
   FLARE_INPUT_MAP_DEF( GamePadMap, GamePad, 16 );
   FLARE_INPUT_MAP_DEF( GamePadAxisMap, GamePadAxis, 6 );
}