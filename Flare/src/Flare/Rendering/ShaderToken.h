#pragma once
#include "Compilation/ConstantExpressions.h"

namespace Flare::Rendering
{
   enum class TokenID : int
   {
      ShaderType = 0,
   };

   constexpr static const char* SHADER_TOKEN_NAMES[] =
   {
      "#!ShaderType:",
   };

   template<typename const TokenID _TokenID>
   struct Token
   {
      constexpr static const char* Name = SHADER_TOKEN_NAMES[(int)_TokenID];
      constexpr static const size_t Size = Utility::Compilation::ConstStrLen( Name );
   };
}