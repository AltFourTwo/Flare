#pragma once
#include "Flare/Rendering/VertexArray.h"
#include "OpenGLObject.h"

namespace Flare::Rendering
{
   class OpenGLVertexArray : public VertexArray, OpenGLObject
   {
      /*****   VARIABLES   *****/
      private:
      std::vector< Ref<VertexBuffer>> m_VertexBuffers;
      Ref<IndexBuffer> m_IndexBuffer;

      /*****  C-TOR D-TOR  *****/
      public:
      OpenGLVertexArray();
      virtual ~OpenGLVertexArray();

      /*****   FUNCTIONS   *****/
      public:
      virtual void Bind() const override;
      virtual void Unbind() const override;

      /*****   GETTERS   *****/
      public:
      virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const override { return m_VertexBuffers; }
      virtual const Ref<IndexBuffer>& GetIndexBuffer() const override { return m_IndexBuffer; }

      /*****   SET&ADD   *****/
      public:
      virtual void AddVertexBuffer( Ref<VertexBuffer>& a_VertexBuffer ) override;
      virtual void SetIndexBuffer( Ref<IndexBuffer>& a_IndexBuffer ) override;
   };
}