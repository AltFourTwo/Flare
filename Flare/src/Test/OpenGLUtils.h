#pragma once

#include "Flare/Core.h"

#include <string>
#include <sstream>
#include <fstream>

namespace Flare::OpenGL
{
   enum class ShaderType
   {
      None = -1,
      Vertex = 0,
      Fragment = 1
   };

   struct ShaderSource
   {
      /*****   CLASS   VARIABLES    *****/
      ShaderType m_Type = ShaderType::None;
      std::stringstream m_Source;
   };

   struct ShaderProgramSource
   {
      std::string m_VertexSource;
      std::string m_FragmentSource;
   };

   ShaderProgramSource ParseProgram( const std::string& a_FilePath );
   unsigned int CompileShader( unsigned int a_Type, const std::string& a_Source );
   unsigned int CreateShaderProgram( const std::string& a_VertexShaderSource, const std::string& a_FragmentShaderSource );

}