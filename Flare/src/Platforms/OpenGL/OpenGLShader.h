#pragma once
#include "Flare/Rendering/Shader.h"
#include "OpenGLObject.h"

#include <string>

namespace Flare::Rendering
{
   class OpenGLShader : public Shader, OpenGLObject
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      OpenGLShader( const std::string& a_VertexSource, const std::string& a_PixelSource );
      virtual ~OpenGLShader();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual void Bind() const;
      virtual void Unbind() const;
   };
}