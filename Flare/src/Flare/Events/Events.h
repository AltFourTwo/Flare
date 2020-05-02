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
         Application = Bits::BIT00,
         Window = Bits::BIT01,
         Input = Bits::BIT02,
         Keyboard = Bits::BIT03,
         Mouse = Bits::BIT04,
         MouseButton = Bits::BIT05,
      };
   };

   using EventCategory = EVENT_CATEGORY_SCOPE::EventCategory;
}

#include "Event.h"
#include "ApplicationEvent.h"
#include "WindowEvent.h"
#include "KeyEvent.h"
#include "MouseEvent.h"
#include "EventDispatcher.h"