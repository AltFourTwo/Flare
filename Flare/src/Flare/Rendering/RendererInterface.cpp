#include "FlarePCH.h"
#include "Flare/Logging/Console.h"
#include "RendererInterface.h"

// Following includes should be surrounded by ifdefs according to platform.
#include "Platforms/OpenGL/OpenGLRendererInterface.h"

namespace Flare::Rendering
{
   /*****   CLASS   C-TOR D-TOR  *****/
   RendererInterface::RendererInterface( API a_API ) :
      m_API( a_API )
   {}

   /*****   CLASS   FUNCTIONS    *****/
   RendererInterface* RendererInterface::CreateInterface( API a_API )
   {
      switch ( a_API )
      {
         case API::None:
            FLARE_CORE_ASSERT( false, { "Chosen API is [None]. Cannot proceed." } );
            return nullptr; // TODO Exception.

         case API::OpenGL:
            return new OpenGLRendererInterface();

         default:
            FLARE_CORE_ASSERT( false, { "Unknown Renderer API! Cannot proceed." } );
            return nullptr; // TODO Exception.
      }
   }
}