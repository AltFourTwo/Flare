#pragma once
#include "Flare/Configuration/Configuration.h"
#include "Flare/Logging/Console.h"
#include "ShaderDataType.h"

namespace Flare::Rendering
{
   // Implementation of this class is per API
   class ShaderDataTypeMap
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      static const uint8_t s_DataTypeSizes[64];
      static const char* s_DataTypeNames[64];

      /*****   CLASS   FUNCTIONS    *****/
      public:
      inline static const uint8_t GetSizeOfType( ShaderDataType::DataType a_DataType ) { return s_DataTypeSizes[a_DataType]; }
      inline static const char* GetNameOfType( ShaderDataType::DataType a_DataType ) { return s_DataTypeNames[a_DataType]; }
   };
}