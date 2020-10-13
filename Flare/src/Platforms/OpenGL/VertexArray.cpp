#include "FlarePCH.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

#include <glfw/glfw3.h>
#include <glad/glad.h>


namespace Flare::OpenGL
{
   /*****   CLASS   C-TOR D-TOR  *****/
   VertexArray::VertexArray()
   {
      // Vertex Array Object
      GL_DEBUG_WRAPPER( glGenVertexArrays( 1, &m_RendererID ) );
      GL_DEBUG_WRAPPER( glBindVertexArray( m_RendererID ) );
   }

   VertexArray::~VertexArray()
   {
      GL_DEBUG_WRAPPER( glDeleteVertexArrays( 1, &m_RendererID ) );
   }

   /*****   CLASS   FUNCTIONS    *****/
   void VertexArray::Bind() const
   {
      GL_DEBUG_WRAPPER( glBindVertexArray( m_RendererID ) );
   }

   void VertexArray::Unbind() const
   {
      GL_DEBUG_WRAPPER( glBindVertexArray( 0 ) );
   }

   void VertexArray::RegisterBuffer( const VertexBuffer& a_VertexBuffer )
   {

   }

   void VertexArray::RegisterBuffer( const VertexBuffer& a_VertexBuffer, const VertexBufferLayout& a_BufferLayout )
   {
      a_VertexBuffer.Bind();

      std::vector<VertexBufferElement> x_Elements = a_BufferLayout.GetElements();
      unsigned int x_Offset = 0;

      for ( unsigned int i = 0; i < x_Elements.size(); i++ )
      {
         const VertexBufferElement x_Element = x_Elements[i];

         // Must enable Vertex Attribute Pointers, before or after they are set does not matter. Where it matters is which buffer is bound. (glBindBuffer)
         //                       Index defined in shader
         GL_DEBUG_WRAPPER( glEnableVertexAttribArray( i ) );

         // Vertex Attribute Pointers.
         // Index, size of vertex, Data Type, normalized, stride, offset
         GL_DEBUG_WRAPPER( glVertexAttribPointer( i, x_Element.m_Count, x_Element.m_Type, x_Element.m_Normalized, a_BufferLayout.GetStride(), (const void*)x_Offset ) );

         x_Offset += x_Element.m_Count * VertexBufferElement::GetSizeOfType( x_Element.m_Type );
      }
   }
}