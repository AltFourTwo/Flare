#pragma once

#include "BitFlags/BitMasks.h"
#include "SquareFlare/Core.h"

namespace SquareFlare::Events
{
   namespace Bits = ::Utility::BitFlags::BitMasks;

   enum class EventType
   {
      None = 0,
      WindowClose,
      WindowResize,
      WindowFocus,
      WindowLostFocus,
      WindowMoved,

      AppTick,
      AppUpdate,
      AppRender,

      KeyPressed,
      KeyRepeat,
      KeyReleased,

      MouseButtonPressed,
      MouseButtonReapeat,
      MouseButtonReleased,
      MouseMoved,
      MouseScrolled,

   };

   struct EVENT_CATEGORY_SCOPE
   {
      enum EventCategory
      {
         None = 0,
         Application = Bits::BIT00,
         Input = Bits::BIT01,
         Keyboard = Bits::BIT02,
         Mouse = Bits::BIT03,
         MouseButton = Bits::BIT04,
      };
   };

   using EventCategory = EVENT_CATEGORY_SCOPE::EventCategory;
}