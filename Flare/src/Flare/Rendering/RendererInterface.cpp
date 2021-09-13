#include "FlarePCH.h"
#include "RendererInterface.h"

#include "Flare/Logging/Console.h"

// Following includes should be surrounded by ifdefs according to platform.
#include "Platforms/OpenGL/OpenGLRendererInterface.h"

namespace Flare::Rendering
{
   /*****  C-TOR D-TOR  *****/
   RendererInterface::RendererInterface( API a_API ) :
      m_API( a_API )
   {}

   /*****   FUNCTIONS   *****/
   Ref<RendererInterface> RendererInterface::CreateInterface( API a_API )
   {
      switch ( a_API )
      {
         case API::None:
            FLARE_CORE_ASSERT( false, "Chosen API is [None]. Cannot proceed." ); // TODO more logs & error codes.
            return nullptr; // TODO Exception.

         case API::OpenGL:
            return std::make_shared<OpenGLRendererInterface>();

         default:
            FLARE_CORE_ASSERT( false, "Unknown Renderer API! Cannot proceed." ); // TODO more logs & error codes.
            return nullptr; // TODO Exception.
      }
   }
}