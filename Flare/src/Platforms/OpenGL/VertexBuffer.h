#pragma once

namespace Flare::OpenGL
{
   class VertexBuffer
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      unsigned int m_RendererID;
      
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      VertexBuffer(const void* a_Data, unsigned int a_Size);
      ~VertexBuffer();

      /*****   CLASS   FUNCTIONS    *****/
      void Bind() const;
      void Unbind() const;
   };
}
