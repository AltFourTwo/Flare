#pragma once
#include "Flare/Rendering/ShaderDataType.h"

#include <glad/glad.h>

namespace Flare::Rendering
{
   class OpenGLShaderDataTypes
   {
      /*****   CLASS   FUNCTIONS    *****/
      public:
      static const char* GetNameOfType( ShaderDataType::DataType a_DataType );
      static const GLenum GetUnderlyingTypeOfType( ShaderDataType::DataType a_DataType );
   };
}