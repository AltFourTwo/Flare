#pragma once

#include "Flare/Configuration/Configuration.h"
#include "Flare/UserInput/InputMaps.h"
#include "Flare/Rendering/ShaderDataTypeMap.h"

namespace Flare::UserInput
{
   KeyMap&& GetAPIKeyMap( Configuration::RendererAPI a_ConfigValue );
}

namespace Flare::Rendering
{
   ShaderDataTypeMap&& GetAPIDataTypeMap( Configuration::RendererAPI a_ConfigValue );
}