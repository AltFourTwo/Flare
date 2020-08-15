#pragma once

namespace Flare::UserInput
{
#define FLARE_CODE_UNDEFINED        -1

#define FLARE_KEY_0                  0
#define FLARE_KEY_1                  1
#define FLARE_KEY_2                  2
#define FLARE_KEY_3                  3
#define FLARE_KEY_4                  4
#define FLARE_KEY_5                  5
#define FLARE_KEY_6                  6
#define FLARE_KEY_7                  7
#define FLARE_KEY_8                  8
#define FLARE_KEY_9                  9
#define FLARE_KEY_A                  10
#define FLARE_KEY_B                  11
#define FLARE_KEY_C                  12
#define FLARE_KEY_D                  13
#define FLARE_KEY_E                  14
#define FLARE_KEY_F                  15
#define FLARE_KEY_G                  16
#define FLARE_KEY_H                  17
#define FLARE_KEY_I                  18
#define FLARE_KEY_J                  19
#define FLARE_KEY_K                  20
#define FLARE_KEY_L                  21
#define FLARE_KEY_M                  22
#define FLARE_KEY_N                  23
#define FLARE_KEY_O                  24
#define FLARE_KEY_P                  25
#define FLARE_KEY_Q                  26
#define FLARE_KEY_R                  27
#define FLARE_KEY_S                  28
#define FLARE_KEY_T                  29
#define FLARE_KEY_U                  30
#define FLARE_KEY_V                  31
#define FLARE_KEY_W                  32
#define FLARE_KEY_X                  33
#define FLARE_KEY_Y                  34
#define FLARE_KEY_Z                  35
#define FLARE_KEY_SPACE              36
#define FLARE_KEY_GRAVE_ACCENT       37 /* ` */
#define FLARE_KEY_MINUS              38 /* - */
#define FLARE_KEY_EQUAL              39 /* = */
#define FLARE_KEY_LEFT_BRACKET       40 /* [ */
#define FLARE_KEY_RIGHT_BRACKET      41 /* ] */
#define FLARE_KEY_SEMICOLON          42 /* ; */
#define FLARE_KEY_APOSTROPHE         43 /* ' */
#define FLARE_KEY_COMMA              44 /* , */
#define FLARE_KEY_PERIOD             45 /* . */
#define FLARE_KEY_SLASH              46 /* / */
#define FLARE_KEY_BACKSLASH          47 /* \ */
#define FLARE_KEY_WORLD_1            48 /* non-US #1 */
#define FLARE_KEY_WORLD_2            49 /* non-US #2 */

// Navigation Keys
#define FLARE_KEY_ESCAPE             50
#define FLARE_KEY_ENTER              51
#define FLARE_KEY_TAB                52
#define FLARE_KEY_BACKSPACE          53
#define FLARE_KEY_INSERT             54
#define FLARE_KEY_DELETE             55
#define FLARE_KEY_RIGHT              56
#define FLARE_KEY_LEFT               57
#define FLARE_KEY_DOWN               58
#define FLARE_KEY_UP                 59
#define FLARE_KEY_PAGE_UP            60
#define FLARE_KEY_PAGE_DOWN          61
#define FLARE_KEY_HOME               62
#define FLARE_KEY_END                63
#define FLARE_KEY_CAPS_LOCK          64
#define FLARE_KEY_SCROLL_LOCK        65
#define FLARE_KEY_NUM_LOCK           66
#define FLARE_KEY_PRINT_SCREEN       67
#define FLARE_KEY_PAUSE              68
#define FLARE_UNUSED_CODE_69         69

// Modifier keys
#define FLARE_KEY_LEFT_SHIFT         70
#define FLARE_KEY_LEFT_CONTROL       71
#define FLARE_KEY_LEFT_ALT           72
#define FLARE_KEY_LEFT_SUPER         73
#define FLARE_KEY_RIGHT_SHIFT        74
#define FLARE_KEY_RIGHT_CONTROL      75
#define FLARE_KEY_RIGHT_ALT          76
#define FLARE_KEY_RIGHT_SUPER        77
#define FLARE_KEY_MENU               78

// Unused
#define FLARE_UNUSED_CODE_79         79

// Keypad
#define FLARE_KEY_KP_0               80
#define FLARE_KEY_KP_1               81
#define FLARE_KEY_KP_2               82
#define FLARE_KEY_KP_3               83
#define FLARE_KEY_KP_4               84
#define FLARE_KEY_KP_5               85
#define FLARE_KEY_KP_6               86
#define FLARE_KEY_KP_7               87
#define FLARE_KEY_KP_8               88
#define FLARE_KEY_KP_9               89
#define FLARE_KEY_KP_DECIMAL         90
#define FLARE_KEY_KP_DIVIDE          91
#define FLARE_KEY_KP_MULTIPLY        92
#define FLARE_KEY_KP_SUBTRACT        93
#define FLARE_KEY_KP_ADD             94
#define FLARE_KEY_KP_ENTER           95
#define FLARE_KEY_KP_EQUAL           96

// Unused
#define FLARE_UNUSED_CODE_97         97
#define FLARE_UNUSED_CODE_98         98
#define FLARE_UNUSED_CODE_99         99
#define FLARE_UNUSED_CODE_100        100

// F Keys
#define FLARE_KEY_F1                 101
#define FLARE_KEY_F2                 102
#define FLARE_KEY_F3                 103
#define FLARE_KEY_F4                 104
#define FLARE_KEY_F5                 105
#define FLARE_KEY_F6                 106
#define FLARE_KEY_F7                 107
#define FLARE_KEY_F8                 108
#define FLARE_KEY_F9                 109
#define FLARE_KEY_F10                110
#define FLARE_KEY_F11                111
#define FLARE_KEY_F12                112
#define FLARE_KEY_F13                113
#define FLARE_KEY_F14                114
#define FLARE_KEY_F15                115
#define FLARE_KEY_F16                116
#define FLARE_KEY_F17                117
#define FLARE_KEY_F18                118
#define FLARE_KEY_F19                119
#define FLARE_KEY_F20                120
#define FLARE_KEY_F21                121
#define FLARE_KEY_F22                122
#define FLARE_KEY_F23                123
#define FLARE_KEY_F24                124
#define FLARE_KEY_F25                125

// Unused
#define FLARE_UNUSED_CODE_126        126
#define FLARE_UNUSED_CODE_127        127


// Modifiers
#define FLARE_MOD_SHIFT              0
#define FLARE_MOD_CONTROL            1
#define FLARE_MOD_ALT                2
#define FLARE_MOD_SUPER              3
#define FLARE_MOD_CAPS_LOCK          4
#define FLARE_MOD_NUM_LOCK           5


// Mouse Buttons
#define FLARE_MOUSE_BUTTON_1         0
#define FLARE_MOUSE_BUTTON_2         1
#define FLARE_MOUSE_BUTTON_3         2
#define FLARE_MOUSE_BUTTON_4         3
#define FLARE_MOUSE_BUTTON_5         4
#define FLARE_MOUSE_BUTTON_6         5
#define FLARE_MOUSE_BUTTON_7         6
#define FLARE_MOUSE_BUTTON_8         7
#define FLARE_MOUSE_BUTTON_LEFT      FLARE_MOUSE_BUTTON_1
#define FLARE_MOUSE_BUTTON_RIGHT     FLARE_MOUSE_BUTTON_2
#define FLARE_MOUSE_BUTTON_MIDDLE    FLARE_MOUSE_BUTTON_3


// Joystick
#define FLARE_JOYSTICK_1             0
#define FLARE_JOYSTICK_2             1
#define FLARE_JOYSTICK_3             2
#define FLARE_JOYSTICK_4             3
#define FLARE_JOYSTICK_5             4
#define FLARE_JOYSTICK_6             5
#define FLARE_JOYSTICK_7             6
#define FLARE_JOYSTICK_8             7
#define FLARE_JOYSTICK_9             8
#define FLARE_JOYSTICK_10            9
#define FLARE_JOYSTICK_11            10
#define FLARE_JOYSTICK_12            11
#define FLARE_JOYSTICK_13            12
#define FLARE_JOYSTICK_14            13
#define FLARE_JOYSTICK_15            14
#define FLARE_JOYSTICK_16            15


// Gamepad buttons
#define FLARE_GAMEPAD_BUTTON_1               0
#define FLARE_GAMEPAD_BUTTON_2               1
#define FLARE_GAMEPAD_BUTTON_3               2
#define FLARE_GAMEPAD_BUTTON_4               3
#define FLARE_GAMEPAD_BUTTON_LEFT_BUMPER     4
#define FLARE_GAMEPAD_BUTTON_RIGHT_BUMPER    5
#define FLARE_GAMEPAD_BUTTON_CENTER_LEFT     6
#define FLARE_GAMEPAD_BUTTON_CENTER_RIGHT    7
#define FLARE_GAMEPAD_BUTTON_CENTER          8
#define FLARE_GAMEPAD_BUTTON_LEFT_THUMB      9
#define FLARE_GAMEPAD_BUTTON_RIGHT_THUMB     10
#define FLARE_GAMEPAD_BUTTON_DPAD_UP         11
#define FLARE_GAMEPAD_BUTTON_DPAD_RIGHT      12
#define FLARE_GAMEPAD_BUTTON_DPAD_DOWN       13
#define FLARE_GAMEPAD_BUTTON_DPAD_LEFT       14

// Gamepad axis
#define GLFW_GAMEPAD_AXIS_LEFT_X        0
#define GLFW_GAMEPAD_AXIS_LEFT_Y        1
#define GLFW_GAMEPAD_AXIS_RIGHT_X       2
#define GLFW_GAMEPAD_AXIS_RIGHT_Y       3
#define GLFW_GAMEPAD_AXIS_LEFT_TRIGGER  4
#define GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER 5
}