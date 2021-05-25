#pragma once

#include <string>

namespace Utility::Strings
{
   enum class GlyphFlags : int
   {
      None = 0x00,
      Symbol = 0x01,
      Number = 0x02,
      LowerCase = 0x04,
      UpperCase = 0x08,
   };

   constexpr static const char LowerWithDiacriticsA[] = { 'à','á','â','ã','ä','å','æ' };
   constexpr static const char UpperWithDiacriticsA[] = { 'À','Á','Â','Ã','Ä','Å','Æ' };
   
   template<typename char _Char, typename GlyphFlags _Flags>
   struct Glyph : std::char_traits<_Char>
   {
      constexpr static const bool IsSymbol = _Flags & GlyphFlags::Symbol;
      constexpr static const bool IsNumber = _Flags & GlyphFlags::Number;
      constexpr static const bool IsLowerCase = _Flags & GlyphFlags::LowerCase;
      constexpr static const bool IsUpperCase = _Flags & GlyphFlags::UpperCase;
      constexpr static const char LowerCase = _Char;
      constexpr static const char UpperCase = _Char;
   };

   template<>
   struct Glyph<_Char, GlyphFlags::None> {};

   template<>
   struct Glyph<'a', GlyphFlags::LowerCase>
   {
      constexpr static const char LowerCase = 'a';
      constexpr static const char UpperCase = 'A';
      
   };
}