#include "FlarePCH.h"
#include "Renderer.h"

#include "Flare/Rendering/ShaderDataTypeMap.h"

#include "Platforms/Utils/PlatformUtils.h"

namespace Flare::Rendering
{
   Configuration::RendererAPI Renderer::s_RendererAPI = Configuration::RendererAPI::OpenGL;
   ShaderDataTypeMap Renderer::s_ShaderDataTypeMap = GetAPIDataTypeMap(s_RendererAPI);
}