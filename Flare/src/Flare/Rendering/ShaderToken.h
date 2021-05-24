#pragma once

namespace Flare::Rendering
{
   enum class TokenID : int
   {
      ShaderType = 0,
   };

   constexpr static const char* SHADER_TOKEN_NAMES[] =
   {
      "#!Type",
   };

   template<typename const TokenID _TokenID>
   struct Token
   {
      private:
      constexpr static const size_t GetLengthOfName( const char* a_Name )
      {
         size_t x_Size = 0;
         const char* x_Current = a_Name;

         while ( *x_Current != 0 )
         {
            x_Current++;
            x_Size++;
         }

         return x_Size;
      }

      public:
      constexpr static const char* Name = SHADER_TOKEN_NAMES[(int)_TokenID];
      constexpr static const size_t Size = GetLengthOfName( SHADER_TOKEN_NAMES[(int)_TokenID] );
   };
}