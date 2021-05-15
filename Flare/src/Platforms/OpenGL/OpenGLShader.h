#pragma once
#include "Flare/Rendering/Shader.h"
#include "OpenGLObject.h"

#include <string>
#include <glad/glad.h>

namespace Flare::Rendering
{
   class OpenGLShader : public Shader, OpenGLObject
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      mutable std::unordered_map<std::string, GLint> m_UniformLocationCache;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      OpenGLShader( const std::string& a_VertexSource, const std::string& a_PixelSource );
      virtual ~OpenGLShader();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual void Bind() const override;
      virtual void Unbind() const override;

      GLint GetUniformLocation(const std::string& a_Name) const;

      void UploadUniformFloat4(const std::string& a_Name, const glm::vec4& a_Value);
      void UploadUniformMat4(const std::string& a_Name, const glm::mat4& a_Matrix);
   };
}