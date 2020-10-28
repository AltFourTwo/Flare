#include "FlarePCH.h"
#include "Buffer.h"
#include "Renderer.h"

#include "Flare/Logging/Console.h"
#include "Flare/Configuration/Configuration.h"

// Following includes should be surrounded by ifdefs according to platform.
#include "Platforms/OpenGL/OpenGLBuffer.h"

namespace Flare::Rendering
{
   /****************/
   /* VertexBuffer */
   /****************/

   VertexBuffer* VertexBuffer::Create( float* a_Vertices, uint32_t a_Size )
   {
      switch ( Renderer::CurrentAPI() )
      {
         case Configuration::RendererAPI::None:
            FLARE_CORE_ASSERT( false, { "Renderer API is set to [None]. Cannot proceed." } );
            return nullptr; // TODO Exception.

         case Configuration::RendererAPI::OpenGL:
            return new OpenGLVertexBuffer(a_Vertices, a_Size);
      }

      FLARE_CORE_ASSERT( false, { "Unknown Renderer API! Cannot proceed." } );
      return nullptr;
   }

   /***************/
   /* IndexBuffer */
   /***************/

   IndexBuffer* IndexBuffer::Create( uint32_t* a_Indices, uint32_t a_Count )
   {
      switch ( Renderer::CurrentAPI() )
      {
         case Configuration::RendererAPI::None:
            FLARE_CORE_ASSERT( false, { "Renderer API is set to [None]. Cannot proceed." } );
            return nullptr; // TODO Exception.

         case Configuration::RendererAPI::OpenGL:
            return new OpenGLIndexBuffer( a_Indices, a_Count );
      }

      FLARE_CORE_ASSERT( false, { "Unknown Renderer API! Cannot proceed." } );
      return nullptr;
   }
}