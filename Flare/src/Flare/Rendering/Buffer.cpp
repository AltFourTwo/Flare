#include "FlarePCH.h"
#include "Buffer.h"

#include "Flare/Logging/Console.h"
#include "Renderer.h"
#include "RenderingController.h"

// Following includes should be surrounded by ifdefs according to platform.
#include "Platforms/OpenGL/OpenGLBuffer.h"

namespace Flare::Rendering
{
   /*****************/
   /* BufferElement */
   /*****************/

   /*****   CLASS   C-TOR D-TOR  *****/
   BufferElement::BufferElement() :
      Name( "" ),
      Type( ShaderDataType::DataType::None ),
      Size( 0 ),
      Offset( 0 ),
      Normalized( false )
   {}

   BufferElement::BufferElement( ShaderDataType a_Type, const std::string& a_Name, bool a_Normalized ) :
      Name( a_Name ),
      Type( a_Type ),
      Size( Type.GetSizeOfType() ),
      Offset( 0 ),
      Normalized( a_Normalized )
   {}

   /****************/
   /* BufferLayout */
   /****************/

   /*****   CLASS   C-TOR D-TOR  *****/
   BufferLayout::BufferLayout( const std::initializer_list<BufferElement>& a_Elements ) :
      m_Elements( a_Elements )
   {
      CalculateOffsetAndStride();
   }

   /*****   CLASS   FUNCTIONS    *****/
   void BufferLayout::CalculateOffsetAndStride()
   {
      uint32_t x_Offset = 0;
      m_Stride = 0;

      for ( auto& x_Element : m_Elements )
      {
         x_Element.Offset = x_Offset;
         x_Offset += x_Element.Size;
         m_Stride += x_Element.Size;
      }
   }

   /****************/
   /* VertexBuffer */
   /****************/

   /*****   CLASS   FUNCTIONS    *****/
   Ref<VertexBuffer> VertexBuffer::Create( float* a_Vertices, uint32_t a_Size )
   {
      switch ( RenderingController::GetCurrentRendererUnderlyingAPI() )
      {
         case API::None:
            FLARE_CORE_ASSERT( false, { "Renderer API is set to [None]. Cannot proceed." } );
            return nullptr; // TODO Exception.

         case API::OpenGL:
            return std::make_shared<OpenGLVertexBuffer>( a_Vertices, a_Size );

         default:
            FLARE_CORE_ASSERT( false, { "Unknown Renderer API! Cannot proceed." } );
            return nullptr; // TODO Exception.
      }
   }

   /***************/
   /* IndexBuffer */
   /***************/

   /*****   CLASS   FUNCTIONS    *****/
   Ref<IndexBuffer> IndexBuffer::Create( uint32_t* a_Indices, uint32_t a_Count )
   {
      switch ( RenderingController::GetCurrentRendererUnderlyingAPI() )
      {
         case API::None:
            FLARE_CORE_ASSERT( false, { "Renderer API is set to [None]. Cannot proceed." } );
            return nullptr; // TODO Exception.

         case API::OpenGL:
            return std::make_shared<OpenGLIndexBuffer>( a_Indices, a_Count );

         default:
            FLARE_CORE_ASSERT( false, { "Unknown Renderer API! Cannot proceed." } );
            return nullptr; // TODO Exception.
      }
   }
}