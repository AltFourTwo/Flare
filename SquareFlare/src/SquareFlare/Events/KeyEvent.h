#pragma once

#include "Event.h"

namespace SquareFlare::Events
{
   class SQFL_API KeyEvent : public Event
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      int m_KeyCode;

      //EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

      public:



   };
}
