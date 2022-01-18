#pragma once

#include "Flare/Core.h"
#include "Bits/Bits.h"

namespace Flare::Events
{
   enum class EventType
   {
      Undefined = 0,

      WindowClose,
      WindowResize,
      WindowFocus,
      WindowLostFocus,
      WindowMoved,

      AppTick,
      AppUpdate,
      AppRender,

      KeyPressed,
      KeyReleased,
      KeyRepeated,
      KeyTyped,

      MouseButtonPressed,
      MouseButtonReleased,
      MouseMoved,
      MouseScrolled,

      ClipboardCut,
      ClipboardCopy,
      ClipboardPaste,
   };

   enum class EventCategory : uint32_t
   {
      Undefined = 0,

      Application = Utility::Bits::BIT00,
      Window = Utility::Bits::BIT01,
      Keyboard = Utility::Bits::BIT02,
      Mouse = Utility::Bits::BIT03,
      Clipboard = Utility::Bits::BIT04,

      // Compound categories.
      Input = Keyboard | Mouse,
   };
}
