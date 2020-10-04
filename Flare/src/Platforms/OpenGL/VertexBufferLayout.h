#pragma once

#include "Renderer.h"

#include <vector>

namespace Flare::OpenGL
{
   struct VertexBufferElement
   {
      unsigned int m_Type;
      unsigned int m_Count;
      unsigned char m_Normalized;

      static unsigned int GetSizeOfType( unsigned int a_Type );
   };

   class VertexBufferLayout
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      std::vector<VertexBufferElement> m_Elements;
      unsigned int m_Stride;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      VertexBufferLayout();
      ~VertexBufferLayout();

      /*****   CLASS   FUNCTIONS    *****/
      inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }
      inline unsigned int GetStride() const { return m_Stride; }

      void Push_Float( unsigned int a_Count );
      void Push_Unsigned_Int( unsigned int a_Count );
      void Push_Unsigned_Char( unsigned int a_Count );
   };
}