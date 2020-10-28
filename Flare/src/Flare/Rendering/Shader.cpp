#include "FlarePCH.h"
#include "Shader.h"
#include "Renderer.h"

#include "Flare/Logging/Console.h"
#include "Flare/Configuration/Configuration.h"

// Following includes should be surrounded by ifdefs according to platform.
#include "Platforms/OpenGL/OpenGLShader.h"

namespace Flare::Rendering
{
   Shader* Shader::Create( const std::string& a_VertexSource, const std::string& a_PixelSource )
   {
      switch ( Renderer::CurrentAPI() )
      {
         case Configuration::RendererAPI::None:
            FLARE_CORE_ASSERT( false, { "Renderer API is set to [None]. Cannot proceed." } );
            return nullptr; // TODO Exception.

         case Configuration::RendererAPI::OpenGL:
            return new OpenGLShader( a_VertexSource, a_PixelSource );
      }

      FLARE_CORE_ASSERT( false, { "Unknown Renderer API! Cannot proceed." } );
      return nullptr;
   }
}