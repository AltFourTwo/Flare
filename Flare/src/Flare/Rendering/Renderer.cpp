#include "FlarePCH.h"
#include "Renderer.h"

#include "Platforms/Utils/PlatformUtils.h"

namespace Flare::Rendering
{
   Configuration::RendererAPI Renderer::s_RendererAPI = Configuration::RendererAPI::OpenGL;
}