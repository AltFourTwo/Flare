#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>

namespace Flare::OpenGL
{
   class Shader
   {
      /*****   CLASS   CONSTANTS    *****/
      private:
      enum class ShaderType
      {
         None = -1,
         Vertex = 0,
         Fragment = 1
      };

      /*****   NESTED  CLASSES      *****/
      private:
      struct ShaderSource
      {
         ShaderType m_Type = ShaderType::None;
         std::stringstream m_Source;
      };

      struct ShaderProgramSource
      {
         std::string m_VertexSource;
         std::string m_FragmentSource;
      };

      /*****   CLASS   VARIABLES    *****/
      private:
      std::string m_FilePath;
      unsigned int m_RendererID;
      std::unordered_map<std::string, int> m_UniformLocationCache;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      Shader( const std::string& a_FilePath );
      ~Shader();

      /*****   CLASS   FUNCTIONS    *****/
      public:
      void Bind() const;
      void Undind() const;

      void SetUniform4f( const std::string& a_UniformName, float v0, float v1, float v2, float v3 );

      private:
      unsigned int GetUniformLocation( const std::string& a_UniformName );

      // Shader Creation/Compilation
      ShaderProgramSource ParseShader( const std::string& a_FilePath );
      unsigned int CompileShader( unsigned int a_Type, const std::string& a_Source );
      unsigned int CreateShader( const std::string& a_VertexShaderSource, const std::string& a_FragmentShaderSource );
   };
}