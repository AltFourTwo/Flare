#pragma once
#include "IRendererBindable.h"
#include "Buffer.h"

#include <memory>

namespace Flare::Rendering
{
   class VertexArray : public IRendererBindable
   {
      /*****  C-TOR D-TOR  *****/
      public:
      virtual ~VertexArray() {}

      /*****   FUNCTIONS   *****/
      public:
      static Ref<VertexArray> Create();

      /*****   GETTERS   *****/
      public:
      virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const = 0;
      virtual const Ref<IndexBuffer>& GetIndexBuffer() const = 0;

      /*****   SET&ADD   *****/
      public:
      virtual void AddVertexBuffer( Ref<VertexBuffer>& a_VertexBuffer ) = 0;
      virtual void SetIndexBuffer( Ref<IndexBuffer>& a_IndexBuffer ) = 0;
   };
}