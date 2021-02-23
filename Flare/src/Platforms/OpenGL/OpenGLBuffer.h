#pragma once
#include "Flare/Rendering/Buffer.h"
#include "OpenGLObject.h"

namespace Flare::Rendering
{
   /****************/
   /* VertexBuffer */
   /****************/

   class OpenGLVertexBuffer : public VertexBuffer, OpenGLObject
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      BufferLayout m_Layout;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      OpenGLVertexBuffer( float* a_Vertices, uint32_t a_Size );
      virtual ~OpenGLVertexBuffer();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual void Bind() const override;
      virtual void Unbind() const override;

      /*****   GETTERS   *****/
      inline virtual const BufferLayout& GetLayout() const override;

      /*****   SETTERS   *****/
      inline virtual void SetLayout( const BufferLayout& a_Layout ) override;
   };

   /***************/
   /* IndexBuffer */
   /***************/

   class OpenGLIndexBuffer : public IndexBuffer, OpenGLObject
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      uint32_t m_Count;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      OpenGLIndexBuffer( uint32_t* a_Indices, uint32_t a_Count );
      virtual ~OpenGLIndexBuffer();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual void Bind() const override;
      virtual void Unbind() const override;
      virtual uint32_t GetCount() const  override { return m_Count; }
   };
}