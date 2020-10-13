#pragma once

namespace Flare::OpenGL
{
   class IndexBuffer
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      unsigned int m_RendererID;
      unsigned int m_Count;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      IndexBuffer( const unsigned int* a_Data, unsigned int a_Count );
      ~IndexBuffer();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      void Bind() const;
      void Unbind() const;

      /*****   GETTERS   *****/
      public:
      inline unsigned int GetCount() const { return m_Count; }
   };
}
