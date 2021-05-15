#include "FlarePCH.h"
#include "Renderer.h"

// Temporary, until shader abstraction is complete.
#include "Platforms/OpenGL/OpenGLShader.h"


namespace Flare::Rendering
{
   /*****   CLASS   C-TOR D-TOR  *****/
   Renderer::Renderer( API a_API ) :
      m_CommandInterface(a_API),
      m_SceneData()
   {}

   /*****   CLASS   FUNCTIONS    *****/
   void Renderer::BeginScene( const OrthographicCamera& a_Camera )
   {
      m_SceneData.ViewProjectionMatrix = a_Camera.GetViewProjectionMatrix();
   }

   void Renderer::EndScene()
   {
      // TODO.
   }

   void Renderer::Submit( const std::shared_ptr<Shader>& a_Shader, const std::shared_ptr<VertexArray>& a_VertexArray )
   {
      a_Shader->Bind();
      std::dynamic_pointer_cast<OpenGLShader>( a_Shader )->UploadUniformMat4( "u_ViewProjection", m_SceneData.ViewProjectionMatrix );

      a_VertexArray->Bind();
      m_CommandInterface.DrawIndexed( a_VertexArray );
   }
}