#include "FlarePCH.h"
#include "OpenGLShader.h"

#include "Flare/Logging/Console.h"
#include "Strings/StringUtils.h"

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace Flare::Rendering
{
   /*****     STATIC CONTEXT     *****/
   static GLenum ShaderTypeFromString( const std::string& a_Type )
   {
      if ( Utility::Strings::EqualsCaseInsensitive( a_Type, "vertex" ) )
         return GL_VERTEX_SHADER;
      if ( Utility::Strings::EqualsCaseInsensitive( a_Type, "fragment" ) || Utility::Strings::EqualsCaseInsensitive( a_Type, "pixel" ) )
         return GL_FRAGMENT_SHADER;

      FLARE_CORE_ASSERT( false, { "Unknown shader type !" } );
   }

   /*****   CLASS   C-TOR D-TOR  *****/
   OpenGLShader::OpenGLShader( const std::string& a_Source )
   {
      std::unordered_map<GLenum, std::string> x_SplitSources = PreProcess( a_Source );
      Compile( x_SplitSources );
   }

   OpenGLShader::OpenGLShader( const std::string& a_VertexSource, const std::string& a_PixelSource )
   {
      std::unordered_map<GLenum, std::string> x_SplitSources =
      {
         {GL_VERTEX_SHADER, a_VertexSource},
         {GL_FRAGMENT_SHADER, a_PixelSource}
      };

      Compile( x_SplitSources );
   }

   OpenGLShader::~OpenGLShader()
   {
      glDeleteProgram( m_OpenGLID );
   }

   /*****   CLASS   FUNCTIONS    *****/
   void OpenGLShader::Compile( const std::unordered_map<GLenum, std::string>& a_SplitSources )
   {
      // Some of the code is from Khronos.org's example. May 24 2021.
      // See https://www.khronos.org/opengl/wiki/Shader_Compilation
      // Adapted to codebase standard.

      GLuint x_ProgramID = glCreateProgram();
      std::vector<GLenum> x_GLShaderIDs( a_SplitSources.size() );

      // Create and compile each shader.
      for ( const auto& [x_Type, x_Source] : a_SplitSources )
      {
         // Create and compile shader.
         GLuint x_ShaderID = glCreateShader( x_Type );
         const GLchar* x_SourceCStr = x_Source.c_str();
         glShaderSource( x_ShaderID, 1, &x_SourceCStr, 0 );
         glCompileShader( x_ShaderID );

         // Assert compilation result.
         GLint x_IsCompiled = 0;
         glGetShaderiv( x_ShaderID, GL_COMPILE_STATUS, &x_IsCompiled );
         if ( x_IsCompiled == GL_FALSE )
         {
            // Get log information.
            GLint x_Length = 0;
            glGetShaderiv( x_ShaderID, GL_INFO_LOG_LENGTH, &x_Length );
            std::vector<GLchar> x_InfoLog( x_Length );
            glGetShaderInfoLog( x_ShaderID, x_Length, &x_Length, &x_InfoLog[0] );

            // Delete invalid shader.
            glDeleteShader( x_ShaderID );

            // Log message and assert false.
            std::string x_Message( x_InfoLog.data() );
            FLARE_CORE_ERROR( "GL Message : {0}", { x_Message } );
            FLARE_CORE_ASSERT( false, { "Shader compilation failure!" } );
            break;
         }

         glAttachShader( x_ProgramID, x_ShaderID );
      }

      // Linking stage.
      glLinkProgram( x_ProgramID );

      // Assert linking result.
      GLint x_IsLinked = 0;
      glGetProgramiv( x_ProgramID, GL_LINK_STATUS, (int*)&x_IsLinked );
      if ( x_IsLinked == GL_FALSE )
      {
         // Get log information.
         GLint x_Length = 0;
         glGetProgramiv( x_ProgramID, GL_INFO_LOG_LENGTH, &x_Length );
         std::vector<GLchar> x_InfoLog( x_Length );
         glGetProgramInfoLog( x_ProgramID, x_Length, &x_Length, &x_InfoLog[0] );

         // Delete invalid program.
         glDeleteProgram( x_ProgramID );

         // Delete compiled shaders.
         for ( auto x_ShaderID : x_GLShaderIDs )
            glDeleteShader( x_ShaderID );

         // Log message and assert false.
         std::string x_Message( x_InfoLog.data() );
         FLARE_CORE_ERROR( "{0}", { x_Message } );
         FLARE_CORE_ASSERT( false, { "Shader linking stage failure!" } );

         return;
      }

      // Detach shaders after a successful link.
      for ( auto x_ShaderID : x_GLShaderIDs )
         glDetachShader( x_ProgramID, x_ShaderID );

      m_OpenGLID = x_ProgramID;
   }

   std::unordered_map<GLenum, std::string> OpenGLShader::PreProcess( const std::string& a_Source )
   {
      std::unordered_map<GLenum, std::string> x_SplitSources;

      size_t x_Pos = a_Source.find( Token<TokenID::ShaderType>::Name, 0 );

      while ( x_Pos != std::string::npos )
      {
         size_t x_EOL = a_Source.find_first_of( "\r\n", x_Pos );
         FLARE_CORE_ASSERT( x_EOL != std::string::npos, { " Syntax Error in shader !" } );
         size_t x_BeginPos = x_Pos + Token<TokenID::ShaderType>::Size;
         std::string x_ShaderTypeString = a_Source.substr( x_BeginPos, x_EOL - x_BeginPos );

         GLenum x_ShaderType = ShaderTypeFromString( x_ShaderTypeString );

         // Find the begining of the next line and the position of a potential other shader type token.
         size_t x_ShaderSegmentBegin = a_Source.find_first_not_of( "\r\n", x_EOL );
         FLARE_CORE_ASSERT( x_ShaderSegmentBegin != std::string::npos, { " Syntax Error in shader !" } );
         x_Pos = a_Source.find( Token<TokenID::ShaderType>::Name, x_ShaderSegmentBegin );

         // If x_Pos is string::npos then we have reached the end of the file.
         // Adjust the end position with source size - begining of segment.
         // Otherwise x_Pos - beginning of segment should give the correct count.
         size_t x_ShaderSegmentCountToEnd = x_Pos == std::string::npos ? a_Source.size() - x_ShaderSegmentBegin : x_Pos - x_ShaderSegmentBegin;
         x_SplitSources[x_ShaderType] = a_Source.substr( x_ShaderSegmentBegin, x_ShaderSegmentCountToEnd );
      }

      return x_SplitSources;
   }

   void OpenGLShader::Bind() const
   {
      glUseProgram( m_OpenGLID );
   }

   void OpenGLShader::Unbind() const
   {
      glUseProgram( 0 );
   }

   GLint OpenGLShader::GetUniformLocation( const std::string& a_Name ) const
   {
      if ( m_UniformLocationCache.find( a_Name ) != m_UniformLocationCache.end() )
         return m_UniformLocationCache[a_Name];

      GLint x_Location = glGetUniformLocation( m_OpenGLID, a_Name.c_str() );
      m_UniformLocationCache[a_Name] = x_Location;
      return x_Location;
   }

   void OpenGLShader::UploadUniformFloat4( const std::string& a_Name, const glm::vec4& a_Value )
   {
      GLint x_Location = GetUniformLocation( a_Name );
      glUniform4f( x_Location, a_Value.x, a_Value.y, a_Value.z, a_Value.w );
   }

   void OpenGLShader::UploadUniformMat4( const std::string& a_Name, const glm::mat4& a_Matrix )
   {
      GLint x_Location = GetUniformLocation( a_Name );
      glUniformMatrix4fv( x_Location, 1, GL_FALSE, glm::value_ptr( a_Matrix ) );
   }
}