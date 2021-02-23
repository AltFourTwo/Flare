#pragma once
#include "Flare/Rendering/Rendering.h"
#include "Flare/UserInput/InputMaps.h"

namespace Flare::UserInput
{
   KeyMap&& GetAPIKeyMap( Rendering::API a_ConfigValue );
}