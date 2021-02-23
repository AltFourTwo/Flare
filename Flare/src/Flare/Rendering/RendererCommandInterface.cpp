#include "FlarePCH.h"
#include "RendererCommandInterface.h"
#include "Renderer.h"

namespace Flare::Rendering
{
   /*****   CLASS   C-TOR D-TOR  *****/
   RendererCommandInterface::RendererCommandInterface( API a_API ):
      m_Interface(Rendering::RendererInterface::CreateInterface(a_API))
   {}
}