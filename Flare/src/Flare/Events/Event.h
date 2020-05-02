#pragma once

#include "Events.h"

#include <string>
#include <sstream>

namespace Flare::Events
{
   class FLARE_API Event
   {
      /*****   CLASS   FRIENDS      *****/
      friend class EventDispatcher;

      /*****   CLASS   VARIABLES    *****/
      protected:
      bool m_Handled = false;
      bool m_Intercepted = false;

      /*****   CLASS   FUNCTIONS    *****/
      public:
      virtual std::string ToString() const
      {
         return GetName();
      }

      inline bool IsInCategory( EventCategory a_Category )
      {
         return GetCategoryFlags() & a_Category;
      }

      /*****   GETTERS   *****/
      public:
      virtual EventType GetEventType() const = 0;
      virtual const char* GetName() const = 0;
      virtual int GetCategoryFlags() const = 0;
   };

   /*****   CLASS   OPERATORS    *****/
   inline std::ostream& operator<<( std::ostream& os, Event& e )
   {
      return os << e.ToString();
   }


   // These macros are used as quick definitions of the pure virtual methods in the abstract event class above.
#define FLARE_EVENT_TYPE(a_Type) static EventType GetStaticType() { return EventType::##a_Type; }\
                                virtual EventType GetEventType() const override { return GetStaticType(); }\
                                virtual const char* GetName() const override { return #a_Type; }

#define FLARE_EVENT_CATEGORY(a_Category) virtual int GetCategoryFlags() const override { return a_Category; }
}