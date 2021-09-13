#include "FlarePCH.h"
#include "Shader.h"

#include "Flare/Logging/Console.h"
#include "RenderingController.h"

// Following includes should be surrounded by ifdefs according to platform.
#include "Platforms/OpenGL/OpenGLShader.h"

namespace Flare::Rendering
{
   /*****   FUNCTIONS   *****/
   Ref<Shader> Shader::Create( const std::string& a_Source )
   {
      switch ( RenderingController::GetCurrentRendererUnderlyingAPI() )
      {
         case API::None:
            FLARE_CORE_ASSERT( false, "Renderer API is set to [None]. Cannot proceed." ); // TODO more logs & error codes.
            return nullptr; // TODO Exception.

         case API::OpenGL:
            return std::make_shared<OpenGLShader>( a_Source );

         default:
            FLARE_CORE_ASSERT( false, "Unknown Renderer API! Cannot proceed." ); // TODO more logs & error codes.
            return nullptr; // TODO Exception.
      }
   }

   Ref<Shader> Shader::Create( const std::string& a_VertexSource, const std::string& a_PixelSource )
   {
      switch ( RenderingController::GetCurrentRendererUnderlyingAPI() )
      {
         case API::None:
            FLARE_CORE_ASSERT( false, "Renderer API is set to [None]. Cannot proceed." ); // TODO more logs & error codes.
            return nullptr; // TODO Exception.

         case API::OpenGL:
            return std::make_shared<OpenGLShader>( a_VertexSource, a_PixelSource );

         default:
            FLARE_CORE_ASSERT( false, "Unknown Renderer API! Cannot proceed." ); // TODO more logs & error codes.
            return nullptr; // TODO Exception.
      }
   }
}