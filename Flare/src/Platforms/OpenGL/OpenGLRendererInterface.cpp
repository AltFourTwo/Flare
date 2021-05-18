#include "FlarePCH.h"
#include "OpenGLRendererInterface.h"

#include "Flare/Rendering/VertexArray.h"

#include <glad/glad.h>

namespace Flare::Rendering
{
   /*****   CLASS   C-TOR D-TOR  *****/
   OpenGLRendererInterface::OpenGLRendererInterface() :
      RendererInterface(API::OpenGL)
   {}

   /*****   CLASS   FUNCTIONS    *****/
   void OpenGLRendererInterface::Init()
   {
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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