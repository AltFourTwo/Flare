#pragma once

#include <type_traits>

namespace Utility::Templates
{
   template<typename MainType, typename OtherType>
   inline constexpr auto IsConvertible = std::is_convertible<MainType, OtherType>::value;

   template<typename MainType, typename OtherType>
   using EnableIfConvertible = typename std::enable_if<IsConvertible<MainType, OtherType>>::type;

   template<typename MainType, typename OtherType>
   inline constexpr auto IsDerived = std::is_base_of<OtherType, MainType>::value;

   template<typename MainType, typename OtherType>
   using EnableIfDerived = typename std::enable_if<std::is_base_of<OtherType, MainType>::value, MainType>::type;
}