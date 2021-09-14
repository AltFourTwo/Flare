#pragma once

#ifdef FLARE_FOR_WINDOWS
   
#else
   #error Flare is windows only!
#endif

#ifdef FLARE_DEBUG
   #define FLARE_ENABLE_ASSERTS true
#endif

#if FLARE_ENABLE_ASSERTS
   #define FLARE_ASSERT(x, ...) { if(!(x)) { (*::Flare::Logging::Console::GetInstance().GetClientLogger()).Error( "Assertion Failed: {0}.", __VA_ARGS__ ); __debugbreak(); } }
   #define FLARE_CORE_ASSERT(x, ...) { if(!(x)) { (*::Flare::Logging::Console::GetInstance().GetCoreLogger()).Error( "Assertion Failed: {0}.", __VA_ARGS__ ); __debugbreak(); } }
#else
   #define FLARE_ASSERT(x, ...)
   #define FLARE_CORE_ASSERT(x, ...)
#endif

#define FLARE_BIND_EVENT_FN(x_Func) std::bind(&x_Func, this, std::placeholders::_1)

#include <memory>

namespace Flare
{
   template<typename T>
   using Scope = std::unique_ptr<T>;
   
   template<typename T, typename ... Args>
   constexpr Scope<T> CreateScope( Args&& ... args )
   {
      return std::make_unique<T>(std::forward<Args>(args)...);
   }

   template<typename T>
   using Ref = std::shared_ptr<T>;

   template<typename T, typename ... Args>
   constexpr Ref<T> CreateRef( Args&& ... args )
   {
      return std::make_shared<T>( std::forward<Args>( args )... );
   }
}

#include "Flare/Logging/Console.h"