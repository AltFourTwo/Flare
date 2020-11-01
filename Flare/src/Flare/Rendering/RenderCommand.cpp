#include "FlarePCH.h"
#include "RenderCommand.h"
#include "Renderer.h"

namespace Flare::Rendering
{
   RendererInterface* RenderCommand::s_Interface = RendererInterface::MakeInterface( API::OpenGL );
}