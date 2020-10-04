#include "FlarePCH.h"
#include "VertexBuffer.h"

#include "Renderer.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Flare::OpenGL
{
   /*****   CLASS   C-TOR D-TOR  *****/
   VertexBuffer::VertexBuffer( const void* a_Data, unsigned int a_Size )
   {
      // Genereate a buffer and bind to it.
      GL_DEBUG_WRAPPER( glGenBuffers( 1, &m_RendererID ) );
      GL_DEBUG_WRAPPER( glBindBuffer( GL_ARRAY_BUFFER, m_RendererID ) );

      // Copy data to the buffer.
      //             Type,            Size in bytes          Data (can be null)   usage
      glBufferData( GL_ARRAY_BUFFER, a_Size, a_Data, GL_STATIC_DRAW );
   }

   VertexBuffer::~VertexBuffer()
   {
      GL_DEBUG_WRAPPER( glDeleteBuffers( 1, &m_RendererID ) );
   }

   /*****   CLASS   FUNCTIONS    *****/
   void VertexBuffer::Bind() const
   {
      GL_DEBUG_WRAPPER( glBindBuffer( GL_ARRAY_BUFFER, m_RendererID ) );
   }

   void VertexBuffer::Unbind() const
   {
      GL_DEBUG_WRAPPER( glBindBuffer( GL_ARRAY_BUFFER, 0 ) );
   }
}