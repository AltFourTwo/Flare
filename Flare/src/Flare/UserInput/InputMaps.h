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
      /*****   VARIABLES   *****/
      protected:
      static const int s_InputCodes[T_Size];

      /*****   FUNCTIONS   *****/
      public:
      virtual std::string ToString() const { return GetName(); }

      /*****   OPERATORS    *****/
      public:
      const int& operator[] ( const int a_Index ) const { return s_InputCodes[a_Index]; }

      /*****   GETTERS   *****/
      public:
      InputMapType GetStaticType() { return T_InputMapType; }
      InputMapType GetInputMapType() const { return GetStaticType(); };
      virtual const char* GetName() const = 0;
   };

   class KeyMap : public InputMap<InputMapType::Keyboard, 128>
   {
      public:
      virtual const char* GetName() const override { return "Keyboard"; }
   };

   class ModifierMap : public InputMap<InputMapType::Modifier, 6>
   {
      public:
      virtual const char* GetName() const override { return "Modifier"; }
   };

   class MouseMap : public InputMap<InputMapType::Mouse, 8>
   {
      public:
      virtual const char* GetName() const override { return "Mouse"; }
   };

   class JoystickMap : public InputMap<InputMapType::Joystick, 16>
   {
      public:
      virtual const char* GetName() const override { return "Joystick"; }
   };

   class GamePadMap : public InputMap<InputMapType::GamePad, 16>
   {
      public:
      virtual const char* GetName() const override { return "GamePad"; }
   };

   class GamePadAxisMap : public InputMap<InputMapType::GamePadAxis, 6>
   {
      public:
      virtual const char* GetName() const override { return "GamePadAxis"; }
   };
}