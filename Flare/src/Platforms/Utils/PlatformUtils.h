#pragma once
#include "Flare/Rendering/Rendering.h"
#include "Flare/UserInput/InputMaps.h"

namespace Flare::UserInput
{
   KeyMap&& GetAPIKeyMap( Rendering::API a_ConfigValue );
   ModifierMap&& GetAPIModifierMap( Rendering::API a_ConfigValue );
   MouseMap&& GetAPIMouseMap( Rendering::API a_ConfigValue );
   JoystickMap&& GetAPIJoystickMap( Rendering::API a_ConfigValue );
   GamePadMap&& GetAPIGamePadMap( Rendering::API a_ConfigValue );
   GamePadAxisMap&& GetAPIGamePadAxisMap( Rendering::API a_ConfigValue );
}