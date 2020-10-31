#pragma once

#include "Flare/Configuration/Configuration.h"
#include "Flare/UserInput/InputMaps.h"

namespace Flare::UserInput
{
   KeyMap&& GetAPIKeyMap( Configuration::RendererAPI a_ConfigValue );
}