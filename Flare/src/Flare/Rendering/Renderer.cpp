#include "FlarePCH.h"
#include "Renderer.h"

namespace Flare::Rendering
{
   /*****   CLASS   FUNCTIONS    *****/
   void Renderer::BeginScene()
   {
      // TODO.
   }

   void Renderer::EndScene()
   {
      // TODO.
   }

   void Renderer::Submit( const std::shared_ptr<VertexArray>& a_VertexArray )
   {
      a_VertexArray->Bind();
      RenderCommand::DrawIndexed( a_VertexArray );
   }
}