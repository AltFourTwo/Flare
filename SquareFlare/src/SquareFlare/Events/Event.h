#pragma once

#include "Events.h"

namespace SquareFlare::Events
{
   class SQFL_API Event
   {
      /*****   CLASS   FRIENDS      *****/
      friend class EventDispatcher;

      /*****   CLASS   VARIABLES    *****/
      protected:
      bool m_Handled = false;
      bool m_Intercepted = false;

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual EventType GetEventType() const = 0;
      virtual const char* GetName() const = 0;
      virtual int GetCategoryFlags() const = 0;
      virtual std::string ToString() const {
         return GetName();
      }

      inline bool IsInCategory( EventCategory a_Category )
      {
         return GetCategoryFlags() & a_Category;
      }
   };
}