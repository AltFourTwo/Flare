#include "FlarePCH.h"
#include "OpenGLVertexArray.h"
#include "OpenGLShaderDataTypes.h"
#include "Flare/Logging/Console.h"

#include <glad/glad.h>

namespace Flare::Rendering
{
   /*****   CLASS   C-TOR D-TOR  *****/
   OpenGLVertexArray::OpenGLVertexArray()
   {
      glGenVertexArrays( 1, &m_OpenGLID );
   }

   OpenGLVertexArray::~OpenGLVertexArray()
   {
      glDeleteVertexArrays( 1, &m_OpenGLID );
   }

   /*****   CLASS   FUNCTIONS    *****/
   void OpenGLVertexArray::Bind() const
   {
      glBindVertexArray( m_OpenGLID );
   }

   void OpenGLVertexArray::Unbind() const
   {
      glBindVertexArray( 0 );
   }

   /*****   SET&ADD   *****/
   void OpenGLVertexArray::AddVertexBuffer( std::shared_ptr<VertexBuffer>& a_VertexBuffer )
   {
      FLARE_CORE_ASSERT( a_VertexBuffer->GetLayout().GetElements().size(), { "Vertex Buffer has no layout!" } );

      glBindVertexArray( m_OpenGLID );
      a_VertexBuffer->Bind();

      uint32_t x_Index = 0;
      const auto& x_Layout = a_VertexBuffer->GetLayout();
      for ( const auto& x_Element : x_Layout )
      {
         glEnableVertexAttribArray( x_Index );
         glVertexAttribPointer(
            x_Index,
            x_Element.Type.GetComponentCount(),
            OpenGLShaderDataTypes::GetUnderlyingTypeOfType( x_Element.Type ),
            x_Element.Normalized ? GL_TRUE : GL_FALSE,
            x_Layout.GetStride(),
            (const void*)x_Element.Offset
         );
         x_Index++;
      }

      m_VertexBuffers.push_back( a_VertexBuffer );
   }

   void OpenGLVertexArray::SetIndexBuffer( std::shared_ptr<IndexBuffer>& a_IndexBuffer )
   {
      glBindVertexArray( m_OpenGLID );
      a_IndexBuffer->Bind();

      m_IndexBuffer = a_IndexBuffer;
   }
}