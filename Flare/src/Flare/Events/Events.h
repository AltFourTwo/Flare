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
      KeyReleased,
      KeyRepeated,
      KeyTyped,

      MouseButtonPressed,
      MouseButtonReleased,
      MouseMoved,
      MouseScrolled,

      ClipBoardCut,
      ClipBoardCopy,
      ClipBoardPaste,
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
         ClipBoard = Utility::Bits::Masks::BIT06,
      };
   };

   using EventCategory = EVENT_CATEGORY_SCOPE::EventCategory;
}
