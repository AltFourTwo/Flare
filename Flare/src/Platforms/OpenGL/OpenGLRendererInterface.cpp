#include "FlarePCH.h"
#include "OpenGLRendererInterface.h"

#include "Flare/Rendering/VertexArray.h"

#include <glad/glad.h>

namespace Flare::Rendering
{
   /*****  C-TOR D-TOR  *****/
   OpenGLRendererInterface::OpenGLRendererInterface() :
      RendererInterface(API::OpenGL)
   {}

   /*****   FUNCTIONS   *****/
   void OpenGLRendererInterface::Init()
   {
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   }

   void OpenGLRendererInterface::SetViewport( uint32_t a_X, uint32_t a_Y, uint32_t a_Width, uint32_t a_Height ) const
   {
      glViewport( a_X, a_Y, a_Width, a_Height );
   }

   void OpenGLRendererInterface::SetClearColor( const glm::vec4& a_Color ) const
   {
      glClearColor( a_Color.r, a_Color.g, a_Color.b, a_Color.a );
   }

   void OpenGLRendererInterface::Clear() const
   {
      glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   }

   void OpenGLRendererInterface::DrawIndexed( const std::shared_ptr<VertexArray>& a_VertexArray ) const
   {
      glDrawElements(GL_TRIANGLES, a_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
   }
}