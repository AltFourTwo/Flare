#pragma once
#include "IRendererBindable.h"
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
      bool Normalized;

      /*****   CLASS   C-TOR D-TOR  *****/
      BufferElement();
      BufferElement( ShaderDataType a_Type, const std::string& a_Name, bool a_Normalized = false );
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

      /*****   GETTERS   *****/
      public:
      inline const std::vector<BufferElement>& GetElements() const { return m_Elements; }
      inline const uint32_t GetStride() const { return m_Stride; }

      std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
      std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
      std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
      std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }
   };

   /****************/
   /* VertexBuffer */
   /****************/

   class VertexBuffer : public IRendererBindable
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      virtual ~VertexBuffer() {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      static Ref<VertexBuffer> Create( float* a_Vertices, uint32_t a_Size );

      /*****   GETTERS   *****/
      inline virtual const BufferLayout& GetLayout() const = 0;

      /*****   SETTERS   *****/
      inline virtual void SetLayout( const BufferLayout& a_Layout ) = 0;
   };

   /***************/
   /* IndexBuffer */
   /***************/

   class IndexBuffer : public IRendererBindable
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      virtual ~IndexBuffer() {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      static Ref<IndexBuffer> Create( uint32_t* a_Indices, uint32_t a_Count );
      virtual uint32_t GetCount() const = 0;
   };
}