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
      
   };
}