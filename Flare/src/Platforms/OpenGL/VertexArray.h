#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace Flare::OpenGL
{
   class VertexArray
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      unsigned int m_RendererID;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      VertexArray();
      ~VertexArray();

      void Bind() const;
      void Unbind() const;
      void RegisterBuffer( const VertexBuffer& a_VertexBuffer );
      void RegisterBuffer( const VertexBuffer& a_VertexBuffer, const VertexBufferLayout& a_BufferLayout );
      //void RegisterIndexBuffer();
   };
}
