#include "FlarePCH.h"
#include "OpenGLShaderDataTypes.h"

#include "Flare/Logging/Console.h"

#include <glad/glad.h>

namespace Flare::Rendering
{
   const char* OpenGLShaderDataTypes::GetNameOfType( ShaderDataType::DataType a_DataType )
   {
      switch ( a_DataType )
      {
         // This should never reach GLSL compilation.
         // If it does, the 'NONE' artefact is inserted.
         // GLSL compilation should then lift this as a clear error.
         case ShaderDataType::DataType::None:
            FLARE_CORE_ASSERT( false, { "ShaderDataType 'None' is used!" } );
            return "FLARE_SHADER_DATA_TYPE_NONE"; // None  

         case ShaderDataType::DataType::Bool1:            return "bool";    // Bool1
         case ShaderDataType::DataType::Bool2:            return "bvec2";   // Bool2
         case ShaderDataType::DataType::Bool3:            return "bvec3";   // Bool3
         case ShaderDataType::DataType::Bool4:            return "bvec4";   // Bool4
         case ShaderDataType::DataType::Integer1:         return "int";     // Integer1
         case ShaderDataType::DataType::Integer2:         return "ivec2";   // Integer2
         case ShaderDataType::DataType::Integer3:         return "ivec3";   // Integer3
         case ShaderDataType::DataType::Integer4:         return "ivec4";   // Integer4
         case ShaderDataType::DataType::UnsignedInteger1: return "uint";    // UnsignedInteger1
         case ShaderDataType::DataType::UnsignedInteger2: return "uvec2";   // UnsignedInteger2
         case ShaderDataType::DataType::UnsignedInteger3: return "uvec3";   // UnsignedInteger3
         case ShaderDataType::DataType::UnsignedInteger4: return "uvec4";   // UnsignedInteger4
         case ShaderDataType::DataType::Float1:           return "float";   // Float1
         case ShaderDataType::DataType::Float2:           return "vec2";    // Float2
         case ShaderDataType::DataType::Float3:           return "vec3";    // Float3
         case ShaderDataType::DataType::Float4:           return "vec4";    // Float4
         case ShaderDataType::DataType::Double1:          return "double";  // Double1
         case ShaderDataType::DataType::Double2:          return "dvec2";   // Double2
         case ShaderDataType::DataType::Double3:          return "dvec3";   // Double3
         case ShaderDataType::DataType::Double4:          return "dvec4";   // Double4
         case ShaderDataType::DataType::Matrix2By2:       return "mat2";    // Matrix2By2
         case ShaderDataType::DataType::Matrix2By3:       return "mat2x3";  // Matrix2By3
         case ShaderDataType::DataType::Matrix2By4:       return "mat2x4";  // Matrix2By4
         case ShaderDataType::DataType::Matrix3By2:       return "mat3x2";  // Matrix3By2
         case ShaderDataType::DataType::Matrix3By3:       return "mat3";    // Matrix3By3
         case ShaderDataType::DataType::Matrix3By4:       return "mat3x4";  // Matrix3By4
         case ShaderDataType::DataType::Matrix4By2:       return "mat4x2";  // Matrix4By2
         case ShaderDataType::DataType::Matrix4By3:       return "mat4x3";  // Matrix4By3
         case ShaderDataType::DataType::Matrix4By4:       return "mat4";    // Matrix4By4
         case ShaderDataType::DataType::Matrix2By2D:      return "dmat2";   // Matrix2By2D
         case ShaderDataType::DataType::Matrix2By3D:      return "dmat2x3"; // Matrix2By3D
         case ShaderDataType::DataType::Matrix2By4D:      return "dmat2x4"; // Matrix2By4D
         case ShaderDataType::DataType::Matrix3By2D:      return "dmat3x2"; // Matrix3By2D
         case ShaderDataType::DataType::Matrix3By3D:      return "dmat3";   // Matrix3By3D
         case ShaderDataType::DataType::Matrix3By4D:      return "dmat3x4"; // Matrix3By4D
         case ShaderDataType::DataType::Matrix4By2D:      return "dmat4x2"; // Matrix4By2D
         case ShaderDataType::DataType::Matrix4By3D:      return "dmat4x3"; // Matrix4By3D
         case ShaderDataType::DataType::Matrix4By4D:      return "dmat4";   // Matrix4By4D

         default:
            // Same logic with the 'NONE' case, but sends 'ERROR' instead.
            FLARE_CORE_ASSERT( false, { "Unknown ShaderDataType" } );
            return "FLARE_SHADER_DATA_TYPE_ERROR";
      }
   }

   const GLenum OpenGLShaderDataTypes::GetUnderlyingTypeOfType( ShaderDataType::DataType a_DataType )
   {
      switch ( a_DataType )
      {
         case ShaderDataType::DataType::None:
            FLARE_CORE_ASSERT( false, { "ShaderDataType 'None' is used!" } );
            return 0;

         case ShaderDataType::DataType::Bool1:            return GL_BOOL;
         case ShaderDataType::DataType::Bool2:            return GL_BOOL;
         case ShaderDataType::DataType::Bool3:            return GL_BOOL;
         case ShaderDataType::DataType::Bool4:            return GL_BOOL;
         case ShaderDataType::DataType::Integer1:         return GL_INT;
         case ShaderDataType::DataType::Integer2:         return GL_INT;
         case ShaderDataType::DataType::Integer3:         return GL_INT;
         case ShaderDataType::DataType::Integer4:         return GL_INT;
         case ShaderDataType::DataType::UnsignedInteger1: return GL_UNSIGNED_INT;
         case ShaderDataType::DataType::UnsignedInteger2: return GL_UNSIGNED_INT;
         case ShaderDataType::DataType::UnsignedInteger3: return GL_UNSIGNED_INT;
         case ShaderDataType::DataType::UnsignedInteger4: return GL_UNSIGNED_INT;
         case ShaderDataType::DataType::Float1:           return GL_FLOAT;
         case ShaderDataType::DataType::Float2:           return GL_FLOAT;
         case ShaderDataType::DataType::Float3:           return GL_FLOAT;
         case ShaderDataType::DataType::Float4:           return GL_FLOAT;
         case ShaderDataType::DataType::Double1:          return GL_DOUBLE;
         case ShaderDataType::DataType::Double2:          return GL_DOUBLE;
         case ShaderDataType::DataType::Double3:          return GL_DOUBLE;
         case ShaderDataType::DataType::Double4:          return GL_DOUBLE;
         case ShaderDataType::DataType::Matrix2By2:       return GL_FLOAT;
         case ShaderDataType::DataType::Matrix2By3:       return GL_FLOAT;
         case ShaderDataType::DataType::Matrix2By4:       return GL_FLOAT;
         case ShaderDataType::DataType::Matrix3By2:       return GL_FLOAT;
         case ShaderDataType::DataType::Matrix3By3:       return GL_FLOAT;
         case ShaderDataType::DataType::Matrix3By4:       return GL_FLOAT;
         case ShaderDataType::DataType::Matrix4By2:       return GL_FLOAT;
         case ShaderDataType::DataType::Matrix4By3:       return GL_FLOAT;
         case ShaderDataType::DataType::Matrix4By4:       return GL_FLOAT;
         case ShaderDataType::DataType::Matrix2By2D:      return GL_DOUBLE;
         case ShaderDataType::DataType::Matrix2By3D:      return GL_DOUBLE;
         case ShaderDataType::DataType::Matrix2By4D:      return GL_DOUBLE;
         case ShaderDataType::DataType::Matrix3By2D:      return GL_DOUBLE;
         case ShaderDataType::DataType::Matrix3By3D:      return GL_DOUBLE;
         case ShaderDataType::DataType::Matrix3By4D:      return GL_DOUBLE;
         case ShaderDataType::DataType::Matrix4By2D:      return GL_DOUBLE;
         case ShaderDataType::DataType::Matrix4By3D:      return GL_DOUBLE;
         case ShaderDataType::DataType::Matrix4By4D:      return GL_DOUBLE;

         default:
            // Same logic with the 'NONE' case.
            FLARE_CORE_ASSERT( false, { "Unknown ShaderDataType" } );
            return 0;
      }
   }
}