#include "FlarePCH.h"
#include "OpenGLBuffer.h"

#include <glad\glad.h>

namespace Flare::Rendering
{
   /****************/
   /* VertexBuffer */
   /****************/

   /*****  C-TOR D-TOR  *****/
   OpenGLVertexBuffer::OpenGLVertexBuffer( float* a_Vertices, uint32_t a_Size )
   {
      glCreateBuffers(1, &m_OpenGLID);
      glBindBuffer(GL_ARRAY_BUFFER, m_OpenGLID);
      glBufferData(GL_ARRAY_BUFFER, a_Size, a_Vertices, GL_STATIC_DRAW);
   }

   OpenGLVertexBuffer::~OpenGLVertexBuffer() 
   {
      glDeleteBuffers(1, &m_OpenGLID);
   }

   /*****   FUNCTIONS   *****/
   void OpenGLVertexBuffer::Bind() const
   {
      glBindBuffer(GL_ARRAY_BUFFER, m_OpenGLID);
   }

   void OpenGLVertexBuffer::Unbind() const
   {
      glBindBuffer(GL_ARRAY_BUFFER, 0);
   }

   /*****   GETTERS   *****/
   const BufferLayout& OpenGLVertexBuffer::GetLayout() const
   {
      return m_Layout;
   }

   /*****   SETTERS   *****/
   void OpenGLVertexBuffer::SetLayout( const BufferLayout& a_Layout )
   {
      m_Layout = a_Layout;
   }

   /***************/
   /* IndexBuffer */
   /***************/

   /*****  C-TOR D-TOR  *****/
   OpenGLIndexBuffer::OpenGLIndexBuffer( uint32_t* a_Indices, uint32_t a_Count) :
      m_Count(a_Count)
   {
      glCreateBuffers( 1, &m_OpenGLID );
      glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_OpenGLID );
      glBufferData( GL_ELEMENT_ARRAY_BUFFER, a_Count * sizeof(uint32_t), a_Indices, GL_STATIC_DRAW );
   }

   OpenGLIndexBuffer::~OpenGLIndexBuffer()
   {
      glDeleteBuffers( 1, &m_OpenGLID );
   }

   /*****   FUNCTIONS   *****/
   void OpenGLIndexBuffer::Bind() const
   {
      glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_OpenGLID );
   }

   void OpenGLIndexBuffer::Unbind() const
   {
      glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
   }
}