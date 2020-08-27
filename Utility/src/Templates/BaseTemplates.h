#pragma once

#include <type_traits>

namespace Utility::Templates
{
   template<typename T, typename Other>
   using EnableByInheritance = std::enable_if_t<std::is_convertible_v<T*, Other*>>;
}