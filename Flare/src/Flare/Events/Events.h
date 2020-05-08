#pragma once

#include "Bits/Masks.h"
#include "Flare/Core.h"

namespace Flare::Events
{
   enum class EventType
   {
      None = 0,

      WindowClose,
      WindowResize,
      WindowFocus,
      WindowLostFocus,
      WindowMoved,

      AppTick,
      AppBeforeUpdate,
      AppUpdate,
      AppAfterUpdate,
      AppBeforeRender,
      AppRender,
      AppAfterRender,

      KeyPressed,
      KeyRepeated,
      KeyReleased,

      MouseButtonPressed,
      MouseButtonReleased,
      MouseMoved,
      MouseScrolled,
   };

   struct EVENT_CATEGORY_SCOPE
   {
      enum EventCategory
      {
         None = 0,
         Application = Utility::Bits::Masks::BIT00,
         Window = Utility::Bits::Masks::BIT01,
         Input = Utility::Bits::Masks::BIT02,
         Keyboard = Utility::Bits::Masks::BIT03,
         Mouse = Utility::Bits::Masks::BIT04,
         MouseButton = Utility::Bits::Masks::BIT05,
      };
   };

   using EventCategory = EVENT_CATEGORY_SCOPE::EventCategory;
}
