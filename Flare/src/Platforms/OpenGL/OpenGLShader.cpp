#include "FlarePCH.h"
#include "OpenGLShader.h"

#include "Flare/Logging/Console.h"

#include <string>
#include <glad\glad.h>

namespace Flare::Rendering
{
   OpenGLShader::OpenGLShader( const std::string& a_VertexSource, const std::string& a_PixelSource )
   {
      // Most of the code in the constructor is from Khronos.org's example. Oct 27 2020.
      // See https://www.khronos.org/opengl/wiki/Shader_Compilation 

      // Create an empty vertex shader handle
      GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER );

      // Send the vertex shader source code to GL
      // Note that std::string's .c_str is NULL character terminated.
      const GLchar* source = a_VertexSource.c_str();
      glShaderSource( vertexShader, 1, &source, 0 );

      // Compile the vertex shader
      glCompileShader( vertexShader );

      GLint isCompiled = 0;
      glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &isCompiled );
      if ( isCompiled == GL_FALSE )
      {
         GLint maxLength = 0;
         glGetShaderiv( vertexShader, GL_INFO_LOG_LENGTH, &maxLength );

         // The maxLength includes the NULL character
         std::vector<GLchar> infoLog( maxLength );
         glGetShaderInfoLog( vertexShader, maxLength, &maxLength, &infoLog[0] );

         // We don't need the shader anymore.
         glDeleteShader( vertexShader );

         std::string _message( infoLog.data() );
         FLARE_CORE_ERROR( "{0}", { _message } );
         FLARE_CORE_ASSERT( false, { "Vertex shader compilation failure!" } );

         return;
      }

      // Create an empty fragment shader handle
      GLuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );

      // Send the fragment shader source code to GL
      // Note that std::string's .c_str is NULL character terminated.
      source = a_PixelSource.c_str();
      glShaderSource( fragmentShader, 1, &source, 0 );

      // Compile the fragment shader
      glCompileShader( fragmentShader );

      glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &isCompiled );
      if ( isCompiled == GL_FALSE )
      {
         GLint maxLength = 0;
         glGetShaderiv( fragmentShader, GL_INFO_LOG_LENGTH, &maxLength );

         // The maxLength includes the NULL character
         std::vector<GLchar> infoLog( maxLength );
         glGetShaderInfoLog( fragmentShader, maxLength, &maxLength, &infoLog[0] );

         // We don't need the shader anymore.
         glDeleteShader( fragmentShader );
         // Either of them. Don't leak shaders.
         glDeleteShader( vertexShader );

         std::string _message( infoLog.data() );
         FLARE_CORE_ERROR( "{0}", { _message } );
         std::string _message2 = "Pixel shader compilation failure!";
         FLARE_CORE_ASSERT( false, { _message2 } );

         return;
      }

      // Vertex and fragment shaders are successfully compiled.
      // Now time to link them together into a program.
      // Get a program object.
      m_OpenGLID = glCreateProgram();

      // Attach our shaders to our program
      glAttachShader( m_OpenGLID, vertexShader );
      glAttachShader( m_OpenGLID, fragmentShader );

      // Link our program
      glLinkProgram( m_OpenGLID );

      // Note the different functions here: glGetProgram* instead of glGetShader*.
      GLint isLinked = 0;
      glGetProgramiv( m_OpenGLID, GL_LINK_STATUS, (int*)&isLinked );
      if ( isLinked == GL_FALSE )
      {
         GLint maxLength = 0;
         glGetProgramiv( m_OpenGLID, GL_INFO_LOG_LENGTH, &maxLength );

         // The maxLength includes the NULL character
         std::vector<GLchar> infoLog( maxLength );
         glGetProgramInfoLog( m_OpenGLID, maxLength, &maxLength, &infoLog[0] );

         // We don't need the program anymore.
         glDeleteProgram( m_OpenGLID );
         // Don't leak shaders either.
         glDeleteShader( vertexShader );
         glDeleteShader( fragmentShader );

         std::string _message( infoLog.data() );
         FLARE_CORE_ERROR( "{0}", { _message } );
         FLARE_CORE_ASSERT( false, { "Shader linking stage failure!" } );

         return;
      }

      // Always detach shaders after a successful link.
      glDetachShader( m_OpenGLID, vertexShader );
      glDetachShader( m_OpenGLID, fragmentShader );
   }

   OpenGLShader::~OpenGLShader()
   {
      glDeleteProgram( m_OpenGLID );
   }

   void OpenGLShader::Bind() const
   {
      glUseProgram( m_OpenGLID );
   }

   void OpenGLShader::Unbind() const
   {
      glUseProgram( 0 );
   }
}