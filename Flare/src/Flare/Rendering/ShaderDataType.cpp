#include "FlarePCH.h"
#include "ShaderDataType.h"
#include "Renderer.h"
#include "Flare/Logging/Console.h"

// Following includes should be surrounded by ifdefs according to platform.
#include "Platforms/OpenGL/OpenGLShaderDataTypes.h"

namespace Flare::Rendering
{
   /*****   CLASS   C-TOR D-TOR  *****/
   ShaderDataType::ShaderDataType() :
      m_Type( None )
   {}

   ShaderDataType::ShaderDataType( DataType a_DataType ) :
      m_Type( a_DataType )
   {}

   /*****   GETTERS   *****/
   const uint32_t ShaderDataType::GetComponentCount() const
   {
      switch ( m_Type )
      {
         case ShaderDataType::None:
            FLARE_CORE_ASSERT( false, { "ShaderDataType 'None' is used!" });
            return 0;

         case ShaderDataType::Bool1            : return 1;
         case ShaderDataType::Bool2            : return 2;
         case ShaderDataType::Bool3            : return 3;
         case ShaderDataType::Bool4            : return 4;
         case ShaderDataType::Integer1         : return 1;
         case ShaderDataType::Integer2         : return 2;
         case ShaderDataType::Integer3         : return 3;
         case ShaderDataType::Integer4         : return 4;
         case ShaderDataType::UnsignedInteger1 : return 1;
         case ShaderDataType::UnsignedInteger2 : return 2;
         case ShaderDataType::UnsignedInteger3 : return 3;
         case ShaderDataType::UnsignedInteger4 : return 4;
         case ShaderDataType::Float1           : return 1;
         case ShaderDataType::Float2           : return 2;
         case ShaderDataType::Float3           : return 3;
         case ShaderDataType::Float4           : return 4;
         case ShaderDataType::Double1          : return 1;
         case ShaderDataType::Double2          : return 2;
         case ShaderDataType::Double3          : return 3;
         case ShaderDataType::Double4          : return 4;
         case ShaderDataType::Matrix2By2       : return 2 * 2;
         case ShaderDataType::Matrix2By3       : return 2 * 3;
         case ShaderDataType::Matrix2By4       : return 2 * 4;
         case ShaderDataType::Matrix3By2       : return 3 * 2;
         case ShaderDataType::Matrix3By3       : return 3 * 3;
         case ShaderDataType::Matrix3By4       : return 3 * 4;
         case ShaderDataType::Matrix4By2       : return 4 * 2;
         case ShaderDataType::Matrix4By3       : return 4 * 3;
         case ShaderDataType::Matrix4By4       : return 4 * 4;
         case ShaderDataType::Matrix2By2D      : return 2 * 2;
         case ShaderDataType::Matrix2By3D      : return 2 * 3;
         case ShaderDataType::Matrix2By4D      : return 2 * 4;
         case ShaderDataType::Matrix3By2D      : return 3 * 2;
         case ShaderDataType::Matrix3By3D      : return 3 * 3;
         case ShaderDataType::Matrix3By4D      : return 3 * 4;
         case ShaderDataType::Matrix4By2D      : return 4 * 2;
         case ShaderDataType::Matrix4By3D      : return 4 * 3;
         case ShaderDataType::Matrix4By4D      : return 4 * 4;
      }

      // Same logic with the 'NONE' case.
      FLARE_CORE_ASSERT( false, { "Unknown ShaderDataType" } );
      return 0;
   }

   const uint32_t ShaderDataType::GetSizeOfType() const
   { 
      switch ( m_Type )
      {
         case ShaderDataType::None:
            FLARE_CORE_ASSERT( false, { "ShaderDataType 'None' is used!" });
            return 0;

         case ShaderDataType::Bool1            : return 4;
         case ShaderDataType::Bool2            : return 4 * 2;
         case ShaderDataType::Bool3            : return 4 * 3;
         case ShaderDataType::Bool4            : return 4 * 4;
         case ShaderDataType::Integer1         : return 4;
         case ShaderDataType::Integer2         : return 4 * 2;
         case ShaderDataType::Integer3         : return 4 * 3;
         case ShaderDataType::Integer4         : return 4 * 4;
         case ShaderDataType::UnsignedInteger1 : return 4;
         case ShaderDataType::UnsignedInteger2 : return 4 * 2;
         case ShaderDataType::UnsignedInteger3 : return 4 * 3;
         case ShaderDataType::UnsignedInteger4 : return 4 * 4;
         case ShaderDataType::Float1           : return 4;
         case ShaderDataType::Float2           : return 4 * 2;
         case ShaderDataType::Float3           : return 4 * 3;
         case ShaderDataType::Float4           : return 4 * 4;
         case ShaderDataType::Double1          : return 8;
         case ShaderDataType::Double2          : return 8 * 2;
         case ShaderDataType::Double3          : return 8 * 3;
         case ShaderDataType::Double4          : return 8 * 4;
         case ShaderDataType::Matrix2By2       : return 4 * 2 * 2;
         case ShaderDataType::Matrix2By3       : return 4 * 2 * 3;
         case ShaderDataType::Matrix2By4       : return 4 * 2 * 4;
         case ShaderDataType::Matrix3By2       : return 4 * 3 * 2;
         case ShaderDataType::Matrix3By3       : return 4 * 3 * 3;
         case ShaderDataType::Matrix3By4       : return 4 * 3 * 4;
         case ShaderDataType::Matrix4By2       : return 4 * 4 * 2;
         case ShaderDataType::Matrix4By3       : return 4 * 4 * 3;
         case ShaderDataType::Matrix4By4       : return 4 * 4 * 4;
         case ShaderDataType::Matrix2By2D      : return 8 * 2 * 2;
         case ShaderDataType::Matrix2By3D      : return 8 * 2 * 3;
         case ShaderDataType::Matrix2By4D      : return 8 * 2 * 4;
         case ShaderDataType::Matrix3By2D      : return 8 * 3 * 2;
         case ShaderDataType::Matrix3By3D      : return 8 * 3 * 3;
         case ShaderDataType::Matrix3By4D      : return 8 * 3 * 4;
         case ShaderDataType::Matrix4By2D      : return 8 * 4 * 2;
         case ShaderDataType::Matrix4By3D      : return 8 * 4 * 3;
         case ShaderDataType::Matrix4By4D      : return 8 * 4 * 4;
      }

      // Same logic with the 'NONE' case.
      FLARE_CORE_ASSERT( false, { "Unknown ShaderDataType" } );
      return 0;
   }

   const char* ShaderDataType::GetNameOfType() const 
   { 
      switch ( Renderer::GetCommandInterfaceAPI() )
      {
         case API::None:
            FLARE_CORE_ASSERT( false, { "Renderer API is set to [None]. Cannot proceed." } );
            return nullptr; // TODO Exception.

         case API::OpenGL:
            return OpenGLShaderDataTypes::GetNameOfType(m_Type);
      }
   }
}