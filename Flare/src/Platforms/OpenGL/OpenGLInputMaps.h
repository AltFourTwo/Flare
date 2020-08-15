#pragma once

#include "Flare/UserInput/InputMaps.h"
#include "GLFW/glfw3.h"

namespace Flare::UserInput
{
   class OpenGLKeyMap : public KeyMap {};
   class OpenGLMouseMap : public MouseMap {};
   class OpenGLModifierMap : public ModifierMap {};
   class OpenGLJoystickMap : public JoystickMap {};
   class OpenGLGamePadMap : public GamePadMap {};
   class OpenGLGamePadAxisMap : public GamePadAxisMap {};
}