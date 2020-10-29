#include "FlarePCH.h"
#include "ShaderDataType.h"
#include "ShaderDataTypeMap.h"

namespace Flare::Rendering
{
   /*****   CLASS   C-TOR D-TOR  *****/
   ShaderDataType::ShaderDataType() :
      m_Type( None )
   {}

   ShaderDataType::ShaderDataType( DataType a_DataType ) :
      m_Type( a_DataType )
   {}

   /*****   CLASS   FUNCTIONS    *****/
   const uint8_t ShaderDataType::GetSizeOfType( const ShaderDataTypeMap& a_TypeMap ) const { return a_TypeMap.GetSizeOfType( m_Type ); }
   const char* ShaderDataType::GetNameOfType( const ShaderDataTypeMap& a_TypeMap ) const { return a_TypeMap.GetNameOfType( m_Type ); }
}