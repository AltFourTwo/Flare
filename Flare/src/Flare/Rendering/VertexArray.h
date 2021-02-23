#pragma once
#include "IRendererBindable.h"
#include "Buffer.h"

#include <memory>

namespace Flare::Rendering
{
   class VertexArray : public IRendererBindable
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      virtual ~VertexArray() {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      static VertexArray* Create();

      /*****   GETTERS   *****/
      public:
      virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const = 0;
      virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;

      /*****   SET&ADD   *****/
      public:
      virtual void AddVertexBuffer( std::shared_ptr<VertexBuffer>& a_VertexBuffer ) = 0;
      virtual void SetIndexBuffer( std::shared_ptr<IndexBuffer>& a_IndexBuffer ) = 0;
   };
}