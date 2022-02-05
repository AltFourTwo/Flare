#include "FlarePCH.h"
#include "VertexArray.h"

#include "Flare/Logging/LogService.h"
#include "Renderer.h"
#include "RenderingController.h"

// Following includes should be surrounded by ifdefs according to platform.
#include "Platforms/OpenGL/OpenGLVertexArray.h"

namespace Flare::Rendering
{
   Ref<VertexArray> VertexArray::Create()
   {
      switch ( RenderingController::GetCurrentRendererUnderlyingAPI() )
      {
         case API::None:
            FLARE_CORE_ASSERT( false, "Renderer API is set to [None]. Cannot proceed." ); // TODO more logs & error codes.
            return nullptr; // TODO Exception.

         case API::OpenGL:
            return std::make_shared<OpenGLVertexArray>();

         default:
            FLARE_CORE_ASSERT( false, "Unknown Renderer API! Cannot proceed." ); // TODO more logs & error codes.
            return nullptr; // TODO Exception.
      }
   }
}