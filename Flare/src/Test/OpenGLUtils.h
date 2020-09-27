#pragma once

#include "Flare/Core.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include <string>
#include <sstream>
#include <fstream>

namespace Platform::OpenGL
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
   void GLClearErrors();
   bool GLLogCall( const char* x_Function, const char* x_File, int x_Line );

#define GL_DEBUG_WRAPPER(x) Platform::OpenGL::GLClearErrors();\
   x;\
   ASSERT(Platform::OpenGL::GLLogCall(#x, __FILE__, __LINE__), "OpenGL Error(s) occured!");
}