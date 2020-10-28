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
      static IndexBuffer* Create( uint32_t* a_Indices, uint32_t a_Count );
      virtual uint32_t GetCount() const = 0;

   };
}