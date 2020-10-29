#pragma once
#include "IObject.h"
#include "ShaderDataType.h"

namespace Flare::Rendering
{
   /*****************/
   /* BufferElement */
   /*****************/

   struct BufferElement
   {
      /*****   CLASS   VARIABLES    *****/
      std::string Name;
      ShaderDataType Type;
      uint32_t Size;
      uint32_t Offset;

      /*****   CLASS   C-TOR D-TOR  *****/
      BufferElement();
      BufferElement( ShaderDataType a_Type, const std::string& a_Name );
   };

   /****************/
   /* BufferLayout */
   /****************/

   class BufferLayout
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      std::vector<BufferElement> m_Elements;
      uint32_t m_Stride = 0;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      BufferLayout() : m_Elements() {}
      BufferLayout( const std::initializer_list<BufferElement>& a_Elements );

      /*****   CLASS   FUNCTIONS    *****/
      private:
      void CalculateOffsetAndStride();

      public:
      inline const std::vector<BufferElement>& GetElements() const { return m_Elements; }
   };


   /****************/
   /* VertexBuffer */
   /****************/

   class VertexBuffer : public IObject
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      virtual ~VertexBuffer() {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      static VertexBuffer* Create( float* a_Vertices, uint32_t a_Size );

      /*****   GETTERS   *****/
      inline virtual const BufferLayout& GetLayout() const = 0;

      /*****   SETTERS   *****/
      inline virtual void SetLayout(const BufferLayout& a_Layout) = 0;
   };

   /***************/
   /* IndexBuffer */
   /***************/

   class IndexBuffer : public IObject
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      virtual ~IndexBuffer() {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      static IndexBuffer* Create( uint32_t* a_Indices, uint32_t a_Count );
      virtual uint32_t GetCount() const = 0;

   };
}