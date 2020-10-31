#include "FlarePCH.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Flare/Configuration/Configuration.h"
#include "Flare/Logging/Console.h"

// Following includes should be surrounded by ifdefs according to platform.
#include "Platforms/OpenGL/OpenGLVertexArray.h"

namespace Flare::Rendering
{
   VertexArray* VertexArray::Create()
   {
      switch ( Renderer::CurrentAPI() )
      {
         case Configuration::RendererAPI::None:
            FLARE_CORE_ASSERT( false, { "Renderer API is set to [None]. Cannot proceed." } );
            return nullptr; // TODO Exception.

         case Configuration::RendererAPI::OpenGL:
            return new OpenGLVertexArray();
      }

      FLARE_CORE_ASSERT( false, { "Unknown Renderer API! Cannot proceed." } );
      return nullptr;
   }
}