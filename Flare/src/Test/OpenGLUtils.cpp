#include "FlarePCH.h"
#include "OpenGLUtils.h"

#include <iostream>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Flare::OpenGL
{
   ShaderProgramSource ParseProgram( const std::string& a_FilePath )
   {
      std::ifstream x_Stream( a_FilePath );
      std::string x_Line;
      ShaderType x_Type = ShaderType::None;
      ShaderSource x_ShaderSources[2];

      while ( getline( x_Stream, x_Line ) )
      {
         if ( x_Line.find( "#Shader" ) != std::string::npos )
         {
            if ( x_Line.find( "Vertex" ) != std::string::npos )
               x_Type = ShaderType::Vertex;
            else if ( x_Line.find( "Fragment" ) != std::string::npos )
               x_Type = ShaderType::Fragment;
         }
         else
         {
            x_ShaderSources[(int)x_Type].m_Source << x_Line << "\n";
         }
      }

      return { x_ShaderSources[0].m_Source.str(), x_ShaderSources[1].m_Source.str() };
   }

   unsigned int CompileShader( unsigned int a_Type, const std::string& a_Source )
   {
      unsigned int x_ID = glCreateShader( a_Type );
      const char* x_Source = a_Source.c_str();

      glShaderSource( x_ID, 1, &x_Source, nullptr );
      glCompileShader( x_ID );

      int x_Result;
      glGetShaderiv( x_ID, GL_COMPILE_STATUS, &x_Result );

      if ( x_Result == GL_FALSE )
      {
         int x_Length;
         glGetShaderiv( x_ID, GL_INFO_LOG_LENGTH, &x_Length );

         char* x_Message = (char*)_malloca( x_Length * sizeof( char ) );

         glGetShaderInfoLog( x_ID, x_Length, &x_Length, x_Message );

         std::cout << "Failed to compile " << ( a_Type == GL_VERTEX_SHADER ? "vertex" : "fragment" ) << " shader!" << std::endl;
         std::cout << x_Message << std::endl;

         glDeleteShader( x_ID );
         return 0;
      }

      return x_ID;
   }

   unsigned int CreateShaderProgram( const std::string& a_VertexShaderSource, const std::string& a_FragmentShaderSource )
   {
      unsigned int x_Program = glCreateProgram();
      unsigned int x_VertexShader = CompileShader( GL_VERTEX_SHADER, a_VertexShaderSource );
      unsigned int x_FragmentShader = CompileShader( GL_FRAGMENT_SHADER, a_FragmentShaderSource );

      glAttachShader( x_Program, x_VertexShader );
      glAttachShader( x_Program, x_FragmentShader );
      glLinkProgram( x_Program );
      // glDetachShader(x_VertexShader); // For debugging
      // glDetachShader(x_FragmentShader); // For debugging
      glValidateProgram( x_Program );

      glDeleteShader( x_VertexShader );
      glDeleteShader( x_FragmentShader );

      return x_Program;
   }

}