#pragma once
#include "Flare/Rendering/Shader.h"
#include "OpenGLObject.h"

#include <unordered_map>
#include <glad/glad.h>
#include <glm/glm.hpp>

namespace Flare::Rendering
{
   class OpenGLShader : public Shader, OpenGLObject
   {
      /*****   CLASS   CONSTANTS    *****/
      private:
      const int MAX_NUMBER_OF_SHADERS = 6;
      const char * NEW_LINE_CHARS = "\r\n";

      /*****   CLASS   VARIABLES    *****/
      private:
      mutable std::unordered_map<std::string, GLint> m_UniformLocationCache;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      OpenGLShader( const std::string& a_Source );
      OpenGLShader( const std::string& a_VertexSource, const std::string& a_PixelSource );
      virtual ~OpenGLShader();

      /*****   CLASS   FUNCTIONS    *****/
      private:
      void Compile( const std::unordered_map<GLenum, std::string>& a_SplitSources );
      std::unordered_map<GLenum, std::string> PreProcess( const std::string& a_Source );

      public:
      virtual void Bind() const override;
      virtual void Unbind() const override;

      GLint GetUniformLocation( const std::string& a_Name ) const;

      void UploadUniformFloat4( const std::string& a_Name, const glm::vec4& a_Value );
      void UploadUniformMat4( const std::string& a_Name, const glm::mat4& a_Matrix );
   };
}