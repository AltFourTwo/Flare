#include "FlarePCH.h"

#include "OpenGLInputMaps.h"
#include "Flare/UserInput/InputCodes.h"
#include "GLFW/glfw3.h"

namespace Flare::UserInput
{
   const int OpenGLKeyMap::s_InputCodes[128] =
   {
      // Regular Keys
      GLFW_KEY_0,
      GLFW_KEY_1,
      GLFW_KEY_2,
      GLFW_KEY_3,
      GLFW_KEY_4,
      GLFW_KEY_5,
      GLFW_KEY_6,
      GLFW_KEY_7,
      GLFW_KEY_8,
      GLFW_KEY_9,
      GLFW_KEY_A,
      GLFW_KEY_B,
      GLFW_KEY_C,
      GLFW_KEY_D,
      GLFW_KEY_E,
      GLFW_KEY_F,
      GLFW_KEY_G,
      GLFW_KEY_H,
      GLFW_KEY_I,
      GLFW_KEY_J,
      GLFW_KEY_K,
      GLFW_KEY_L,
      GLFW_KEY_M,
      GLFW_KEY_N,
      GLFW_KEY_O,
      GLFW_KEY_P,
      GLFW_KEY_Q,
      GLFW_KEY_R,
      GLFW_KEY_S,
      GLFW_KEY_T,
      GLFW_KEY_U,
      GLFW_KEY_V,
      GLFW_KEY_W,
      GLFW_KEY_X,
      GLFW_KEY_Y,
      GLFW_KEY_Z,
      GLFW_KEY_SPACE,
      GLFW_KEY_GRAVE_ACCENT,
      GLFW_KEY_MINUS,
      GLFW_KEY_EQUAL,
      GLFW_KEY_LEFT_BRACKET,
      GLFW_KEY_RIGHT_BRACKET,
      GLFW_KEY_SEMICOLON,
      GLFW_KEY_APOSTROPHE,
      GLFW_KEY_COMMA,
      GLFW_KEY_PERIOD,
      GLFW_KEY_SLASH,
      GLFW_KEY_BACKSLASH,
      GLFW_KEY_WORLD_1,
      GLFW_KEY_WORLD_2,

      // Navigation Keys
      GLFW_KEY_ESCAPE,
      GLFW_KEY_ENTER,
      GLFW_KEY_TAB,
      GLFW_KEY_BACKSPACE,
      GLFW_KEY_INSERT,
      GLFW_KEY_DELETE,
      GLFW_KEY_RIGHT,
      GLFW_KEY_LEFT,
      GLFW_KEY_DOWN,
      GLFW_KEY_UP,
      GLFW_KEY_PAGE_UP,
      GLFW_KEY_PAGE_DOWN,
      GLFW_KEY_HOME,
      GLFW_KEY_END,
      GLFW_KEY_CAPS_LOCK,
      GLFW_KEY_SCROLL_LOCK,
      GLFW_KEY_NUM_LOCK,
      GLFW_KEY_PRINT_SCREEN,
      GLFW_KEY_PAUSE,

      // Unused
      FLARE_UNUSED_CODE_69,

      // Modifier Keys
      GLFW_KEY_LEFT_SHIFT,
      GLFW_KEY_LEFT_CONTROL,
      GLFW_KEY_LEFT_ALT,
      GLFW_KEY_LEFT_SUPER,
      GLFW_KEY_RIGHT_SHIFT,
      GLFW_KEY_RIGHT_CONTROL,
      GLFW_KEY_RIGHT_ALT,
      GLFW_KEY_RIGHT_SUPER,
      GLFW_KEY_MENU,

      // Unused
      FLARE_UNUSED_CODE_79,

      // Keypad
      GLFW_KEY_KP_0,
      GLFW_KEY_KP_1,
      GLFW_KEY_KP_2,
      GLFW_KEY_KP_3,
      GLFW_KEY_KP_4,
      GLFW_KEY_KP_5,
      GLFW_KEY_KP_6,
      GLFW_KEY_KP_7,
      GLFW_KEY_KP_8,
      GLFW_KEY_KP_9,
      GLFW_KEY_KP_DECIMAL,
      GLFW_KEY_KP_DIVIDE,
      GLFW_KEY_KP_MULTIPLY,
      GLFW_KEY_KP_SUBTRACT,
      GLFW_KEY_KP_ADD,
      GLFW_KEY_KP_ENTER,
      GLFW_KEY_KP_EQUAL,

      // Unused
      FLARE_UNUSED_CODE_97,
      FLARE_UNUSED_CODE_98,
      FLARE_UNUSED_CODE_99,
      FLARE_UNUSED_CODE_100,

      // Function Keys
      FLARE_KEY_F1,
      FLARE_KEY_F2,
      FLARE_KEY_F3,
      FLARE_KEY_F4,
      FLARE_KEY_F5,
      FLARE_KEY_F6,
      FLARE_KEY_F7,
      FLARE_KEY_F8,
      FLARE_KEY_F9,
      FLARE_KEY_F10,
      FLARE_KEY_F11,
      FLARE_KEY_F12,
      FLARE_KEY_F13,
      FLARE_KEY_F14,
      FLARE_KEY_F15,
      FLARE_KEY_F16,
      FLARE_KEY_F17,
      FLARE_KEY_F18,
      FLARE_KEY_F19,
      FLARE_KEY_F20,
      FLARE_KEY_F21,
      FLARE_KEY_F22,
      FLARE_KEY_F23,
      FLARE_KEY_F24,
      FLARE_KEY_F25,

      // Unused
      FLARE_UNUSED_CODE_126,
      FLARE_UNUSED_CODE_127
   };

   const int OpenGLModifierMap::s_InputCodes[6] = 
   {
      GLFW_MOD_SHIFT,
      GLFW_MOD_CONTROL,
      GLFW_MOD_ALT,
      GLFW_MOD_SUPER,
      GLFW_MOD_CAPS_LOCK,
      GLFW_MOD_NUM_LOCK
   };

   const int OpenGLMouseMap::s_InputCodes[8] =
   {
      GLFW_MOUSE_BUTTON_1,
      GLFW_MOUSE_BUTTON_2,
      GLFW_MOUSE_BUTTON_3,
      GLFW_MOUSE_BUTTON_4,
      GLFW_MOUSE_BUTTON_5,
      GLFW_MOUSE_BUTTON_6,
      GLFW_MOUSE_BUTTON_7,
      GLFW_MOUSE_BUTTON_8
   };

   const int OpenGLJoystickMap::s_InputCodes[16] =
   {
      GLFW_JOYSTICK_1,
      GLFW_JOYSTICK_2,
      GLFW_JOYSTICK_3,
      GLFW_JOYSTICK_4,
      GLFW_JOYSTICK_5,
      GLFW_JOYSTICK_6,
      GLFW_JOYSTICK_7,
      GLFW_JOYSTICK_8,
      GLFW_JOYSTICK_9,
      GLFW_JOYSTICK_10,
      GLFW_JOYSTICK_11,
      GLFW_JOYSTICK_12,
      GLFW_JOYSTICK_13,
      GLFW_JOYSTICK_14,
      GLFW_JOYSTICK_15,
      GLFW_JOYSTICK_16
   };

   const int OpenGLGamePadMap::s_InputCodes[16] =
   {
      GLFW_GAMEPAD_BUTTON_A,
      GLFW_GAMEPAD_BUTTON_B,
      GLFW_GAMEPAD_BUTTON_X,
      GLFW_GAMEPAD_BUTTON_Y,
      GLFW_GAMEPAD_BUTTON_LEFT_BUMPER,
      GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER,
      GLFW_GAMEPAD_BUTTON_BACK,
      GLFW_GAMEPAD_BUTTON_START,
      GLFW_GAMEPAD_BUTTON_GUIDE,
      GLFW_GAMEPAD_BUTTON_LEFT_THUMB,
      GLFW_GAMEPAD_BUTTON_RIGHT_THUMB,
      GLFW_GAMEPAD_BUTTON_DPAD_UP,
      GLFW_GAMEPAD_BUTTON_DPAD_RIGHT,
      GLFW_GAMEPAD_BUTTON_DPAD_DOWN,
      GLFW_GAMEPAD_BUTTON_DPAD_LEFT,

      // Unused
      FLARE_GAMEPAD_UNUSED_BUTTON_16
   };

   const int OpenGLGamePadAxisMap::s_InputCodes[6] =
   {
      GLFW_GAMEPAD_AXIS_LEFT_X,
      GLFW_GAMEPAD_AXIS_LEFT_Y,
      GLFW_GAMEPAD_AXIS_RIGHT_X,
      GLFW_GAMEPAD_AXIS_RIGHT_Y,
      GLFW_GAMEPAD_AXIS_LEFT_TRIGGER,
      GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER
   };
}