#pragma once

#include "Events.h"

#include <string>
#include <sstream>

namespace Flare::Events
{
   class Event
   {
      /*****   FRIENDS     *****/
      friend class EventDispatcher;

      /*****   VARIABLES   *****/
      protected:
      bool m_Handled = false;
      bool m_Intercepted = false;

      /*****   FUNCTIONS   *****/
      public:
      virtual std::string ToString() const { return GetName(); }
      inline bool IsInCategory( EventCategory a_Category ) { return GetCategoryFlags() & static_cast<uint32_t>( a_Category ); }

      /*****   GETTERS   *****/
      public:
      bool IsHandled() { return m_Handled; }
      bool IsIntercepted() { return m_Intercepted; }
      virtual EventType GetEventType() const = 0;
      virtual const char* GetName() const = 0;
      virtual uint32_t GetCategoryFlags() const = 0;
   };

   /*****   OPERATORS    *****/
   inline std::ostream& operator<<( std::ostream& os, Event& e ) { return os << e.ToString(); }
   // TODO : Also implement a std::formatter for event.
}