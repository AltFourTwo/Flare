#pragma once

#include "IObject.h"

namespace Flare::Rendering
{
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
      static IndexBuffer* Create( float* a_Vertices, uint32_t a_Size );

   };
}