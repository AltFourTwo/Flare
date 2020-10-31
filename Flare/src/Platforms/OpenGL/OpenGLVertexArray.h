#pragma once
#include "Flare/Rendering/VertexArray.h"
#include "OpenGLObject.h"

namespace Flare::Rendering
{
   class OpenGLVertexArray : public VertexArray, OpenGLObject
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      std::vector< std::shared_ptr<VertexBuffer>> m_VertexBuffers;
      std::shared_ptr<IndexBuffer> m_IndexBuffer;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      OpenGLVertexArray();
      virtual ~OpenGLVertexArray();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual void Bind() const override;
      virtual void Unbind() const override;

      /*****   GETTERS   *****/
      public:
      virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const override { return m_VertexBuffers; }
      virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override { return m_IndexBuffer; }

      /*****   SET&ADD   *****/
      public:
      virtual void AddVertexBuffer( std::shared_ptr<VertexBuffer>& a_VertexBuffer ) override;
      virtual void SetIndexBuffer( std::shared_ptr<IndexBuffer>& a_IndexBuffer ) override;
   };
}