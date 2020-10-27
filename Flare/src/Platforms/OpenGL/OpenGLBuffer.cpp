#include "FlarePCH.h"
#include "OpenGLBuffer.h"

#include <glad\glad.h>

namespace Flare::Rendering
{

   /****************/
   /* VertexBuffer */
   /****************/

   OpenGLVertexBuffer::OpenGLVertexBuffer( float* a_Vertices, uint32_t a_Size )
   {
      glCreateBuffers(1, &m_ID);
      glBindBuffer(GL_ARRAY_BUFFER, m_ID);
      glBufferData(GL_ARRAY_BUFFER, a_Size, a_Vertices, GL_STATIC_DRAW);
   }

   OpenGLVertexBuffer::~OpenGLVertexBuffer() 
   {
      glDeleteBuffers(1, &m_ID);
   }

   void OpenGLVertexBuffer::Bind() const
   {
      glBindBuffer(GL_ARRAY_BUFFER, m_ID);
   }

   void OpenGLVertexBuffer::Unbind() const
   {
      glBindBuffer(GL_ARRAY_BUFFER, 0);
   }


   /***************/
   /* IndexBuffer */
   /***************/
}