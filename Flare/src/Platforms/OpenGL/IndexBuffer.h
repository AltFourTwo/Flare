#pragma once

namespace Flare::OpenGL
{
   class IndexBuffer
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      unsigned int m_RendererID;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      IndexBuffer( const unsigned int* a_Data, unsigned int a_Count );
      ~IndexBuffer();

      /*****   CLASS   FUNCTIONS    *****/
      void Bind() const;
      void Unbind() const;
   };
}
