#include "FlarePCH.h"
#include "IndexBuffer.h"

#include "Renderer.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Flare::OpenGL
{
   /*****   CLASS   C-TOR D-TOR  *****/
   IndexBuffer::IndexBuffer( const unsigned int* a_Data, unsigned int a_Count )
   {
      // Index Buffer.
      glGenBuffers( 1, &m_RendererID );
      glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_RendererID );
      glBufferData( GL_ELEMENT_ARRAY_BUFFER, a_Count * sizeof( unsigned int ), a_Data, GL_STATIC_DRAW );
   }

   IndexBuffer::~IndexBuffer()
   {
      GL_DEBUG_WRAPPER( glDeleteBuffers( 1, &m_RendererID ) );
   }

   /*****   CLASS   FUNCTIONS    *****/
   void IndexBuffer::Bind() const
   {
      GL_DEBUG_WRAPPER( glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_RendererID ) );
   }

   void IndexBuffer::Unbind() const
   {
      GL_DEBUG_WRAPPER( glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 ) );
   }
}