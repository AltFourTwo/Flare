#include "FlarePCH.h"
#include "Renderer.h"

namespace Flare::Rendering
{
   /*****   CLASS   C-TOR D-TOR  *****/
   Renderer::Renderer( API a_API ) :
      m_CommandInterface(a_API)
   {}

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
      m_CommandInterface.DrawIndexed( a_VertexArray );
   }
}