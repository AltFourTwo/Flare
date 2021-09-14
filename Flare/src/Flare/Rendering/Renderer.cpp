#include "FlarePCH.h"
#include "Renderer.h"

#include "Shader.h"
#include "VertexArray.h"
#include "OrthographicCamera.h"

// Temporary, until shader abstraction is complete.
#include "Platforms/OpenGL/OpenGLShader.h"

namespace Flare::Rendering
{
   /*****  C-TOR D-TOR  *****/
   Renderer::Renderer( API a_API ) :
      m_CommandInterface( a_API ),
      m_SceneData()
   {}

   /*****   FUNCTIONS   *****/
   void Renderer::Init()
   {
      m_CommandInterface.Init();
   }

   void Renderer::OnWindowResize( uint32_t a_Width, uint32_t a_Height )
   {
      m_CommandInterface.SetViewport( 0, 0, a_Width, a_Height );
   }

   void Renderer::BeginScene( const OrthographicCamera& a_Camera )
   {
      m_SceneData.ViewProjectionMatrix = a_Camera.GetViewProjectionMatrix();
   }

   void Renderer::EndScene()
   {
      // TODO.
   }

   void Renderer::Submit( const Ref<Shader>& a_Shader, const Ref<VertexArray>& a_VertexArray )
   {
      a_Shader->Bind();
      std::dynamic_pointer_cast<OpenGLShader>( a_Shader )->UploadUniformMat4( "u_ViewProjection", m_SceneData.ViewProjectionMatrix );

      a_VertexArray->Bind();
      m_CommandInterface.DrawIndexed( a_VertexArray );
   }
}