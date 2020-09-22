#include "FlarePCH.h"
#include "OpenGLTestLayer.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Flare::Testing
{
   OpenGLTestLayer::OpenGLTestLayer() :
      Layer( "OpenGLTestLayer" )
   {
      glBegin( GL_TRIANGLES );
      glVertex2f( -0.5f, -0.5f );
      glVertex2f( 0.0f, 0.5f );
      glVertex2f( 0.5f, -0.5f);
      glEnd();

   }

   void OpenGLTestLayer::OnRender( Time::TimeStep a_TimeStep )
   {

   }

}