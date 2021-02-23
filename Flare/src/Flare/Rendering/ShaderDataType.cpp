#include "FlarePCH.h"
#include "Flare/Logging/Console.h"
#include "Flare/Rendering/RenderingController.h"
#include "ShaderDataType.h"

// Following includes should be surrounded by ifdefs according to platform.
#include "Platforms/OpenGL/OpenGLShaderDataTypes.h"

namespace Flare::Rendering
{
   /*****   CLASS   C-TOR D-TOR  *****/
   ShaderDataType::ShaderDataType() :
      m_Type( DataType::None )
   {}

   ShaderDataType::ShaderDataType( DataType a_DataType ) :
      m_Type( a_DataType )
   {}

   /*****   GETTERS   *****/
   const uint32_t ShaderDataType::GetComponentCount() const
   {
      switch ( m_Type )
      {
         case DataType::None:
            FLARE_CORE_ASSERT( false, { "ShaderDataType 'None' is used!" });
            return 0;

         case DataType::Bool1            : return 1;
         case DataType::Bool2            : return 2;
         case DataType::Bool3            : return 3;
         case DataType::Bool4            : return 4;
         case DataType::Integer1         : return 1;
         case DataType::Integer2         : return 2;
         case DataType::Integer3         : return 3;
         case DataType::Integer4         : return 4;
         case DataType::UnsignedInteger1 : return 1;
         case DataType::UnsignedInteger2 : return 2;
         case DataType::UnsignedInteger3 : return 3;
         case DataType::UnsignedInteger4 : return 4;
         case DataType::Float1           : return 1;
         case DataType::Float2           : return 2;
         case DataType::Float3           : return 3;
         case DataType::Float4           : return 4;
         case DataType::Double1          : return 1;
         case DataType::Double2          : return 2;
         case DataType::Double3          : return 3;
         case DataType::Double4          : return 4;
         case DataType::Matrix2By2       : return 2 * 2;
         case DataType::Matrix2By3       : return 2 * 3;
         case DataType::Matrix2By4       : return 2 * 4;
         case DataType::Matrix3By2       : return 3 * 2;
         case DataType::Matrix3By3       : return 3 * 3;
         case DataType::Matrix3By4       : return 3 * 4;
         case DataType::Matrix4By2       : return 4 * 2;
         case DataType::Matrix4By3       : return 4 * 3;
         case DataType::Matrix4By4       : return 4 * 4;
         case DataType::Matrix2By2D      : return 2 * 2;
         case DataType::Matrix2By3D      : return 2 * 3;
         case DataType::Matrix2By4D      : return 2 * 4;
         case DataType::Matrix3By2D      : return 3 * 2;
         case DataType::Matrix3By3D      : return 3 * 3;
         case DataType::Matrix3By4D      : return 3 * 4;
         case DataType::Matrix4By2D      : return 4 * 2;
         case DataType::Matrix4By3D      : return 4 * 3;
         case DataType::Matrix4By4D      : return 4 * 4;

         default:
            // Same logic with the 'NONE' case.
            FLARE_CORE_ASSERT( false, { "Unknown ShaderDataType" } );
            return 0;
      }
   }

   const uint32_t ShaderDataType::GetSizeOfType() const
   { 
      switch ( m_Type )
      {
         case DataType::None:
            FLARE_CORE_ASSERT( false, { "ShaderDataType 'None' is used!" });
            return 0;

         case DataType::Bool1            : return 4;
         case DataType::Bool2            : return 4 * 2;
         case DataType::Bool3            : return 4 * 3;
         case DataType::Bool4            : return 4 * 4;
         case DataType::Integer1         : return 4;
         case DataType::Integer2         : return 4 * 2;
         case DataType::Integer3         : return 4 * 3;
         case DataType::Integer4         : return 4 * 4;
         case DataType::UnsignedInteger1 : return 4;
         case DataType::UnsignedInteger2 : return 4 * 2;
         case DataType::UnsignedInteger3 : return 4 * 3;
         case DataType::UnsignedInteger4 : return 4 * 4;
         case DataType::Float1           : return 4;
         case DataType::Float2           : return 4 * 2;
         case DataType::Float3           : return 4 * 3;
         case DataType::Float4           : return 4 * 4;
         case DataType::Double1          : return 8;
         case DataType::Double2          : return 8 * 2;
         case DataType::Double3          : return 8 * 3;
         case DataType::Double4          : return 8 * 4;
         case DataType::Matrix2By2       : return 4 * 2 * 2;
         case DataType::Matrix2By3       : return 4 * 2 * 3;
         case DataType::Matrix2By4       : return 4 * 2 * 4;
         case DataType::Matrix3By2       : return 4 * 3 * 2;
         case DataType::Matrix3By3       : return 4 * 3 * 3;
         case DataType::Matrix3By4       : return 4 * 3 * 4;
         case DataType::Matrix4By2       : return 4 * 4 * 2;
         case DataType::Matrix4By3       : return 4 * 4 * 3;
         case DataType::Matrix4By4       : return 4 * 4 * 4;
         case DataType::Matrix2By2D      : return 8 * 2 * 2;
         case DataType::Matrix2By3D      : return 8 * 2 * 3;
         case DataType::Matrix2By4D      : return 8 * 2 * 4;
         case DataType::Matrix3By2D      : return 8 * 3 * 2;
         case DataType::Matrix3By3D      : return 8 * 3 * 3;
         case DataType::Matrix3By4D      : return 8 * 3 * 4;
         case DataType::Matrix4By2D      : return 8 * 4 * 2;
         case DataType::Matrix4By3D      : return 8 * 4 * 3;
         case DataType::Matrix4By4D      : return 8 * 4 * 4;

         default :
            // Same logic with the 'NONE' case.
            FLARE_CORE_ASSERT( false, { "Unknown ShaderDataType" } );
            return 0;
      }
   }

   const char* ShaderDataType::GetNameOfType( const API a_API ) const
   { 
      switch ( a_API )
      {
         case API::None:
            FLARE_CORE_ASSERT( false, { "Renderer API is set to [None]. Cannot proceed." } );
            return nullptr; // TODO Exception.

         case API::OpenGL:
            return OpenGLShaderDataTypes::GetNameOfType(m_Type);

         default :
            // Same logic with the 'NONE' case.
            FLARE_CORE_ASSERT( false, { "Unknown Renderer API! Cannot proceed." } );
            return nullptr; // TODO Exception.
      }
   }
}