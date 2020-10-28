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
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      OpenGLVertexBuffer( float* a_Vertices, uint32_t a_Size );
      virtual ~OpenGLVertexBuffer();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual void Bind() const;
      virtual void Unbind() const;
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
      virtual void Bind() const;
      virtual void Unbind() const;
      virtual uint32_t GetCount() const { return m_Count; }
   };
}