#pragma once

#include "Event.h"

namespace SquareFlare::Events
{
   class SQFL_API ApplicationEvent : public Event
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      ApplicationEvent() {}

      /*****   GETTERS   *****/
      SQFL_EVENT_CATEGORY( EventCategory::Application );
   };

   class SQFL_API AppTickEvent : public ApplicationEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      AppTickEvent() : ApplicationEvent() {}

      /*****   CLASS   FUNCTIONS    *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppTickEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      SQFL_EVENT_TYPE( AppTick );
   };

   class SQFL_API AppBeforeUpdateEvent : public ApplicationEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      AppBeforeUpdateEvent() : ApplicationEvent() {}

      /*****   CLASS   FUNCTIONS    *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppBeforeUpdateEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      SQFL_EVENT_TYPE( AppBeforeUpdate );
   };

   class SQFL_API AppUpdateEvent : public ApplicationEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      AppUpdateEvent() : ApplicationEvent() {}

      /*****   CLASS   FUNCTIONS    *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppUpdateEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      SQFL_EVENT_TYPE( AppUpdate );
   };

   class SQFL_API AppAfterUpdateEvent : public ApplicationEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      AppAfterUpdateEvent() : ApplicationEvent() {}

      /*****   CLASS   FUNCTIONS    *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppAfterUpdateEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      SQFL_EVENT_TYPE( AppAfterUpdate );
   };

   class SQFL_API AppBeforeRenderEvent : public ApplicationEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      AppBeforeRenderEvent() : ApplicationEvent() {}

      /*****   CLASS   FUNCTIONS    *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppBeforeRenderEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      SQFL_EVENT_TYPE( AppBeforeRender );
   };

   class SQFL_API AppRenderEvent : public ApplicationEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      AppRenderEvent() : ApplicationEvent() {}

      /*****   CLASS   FUNCTIONS    *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppRenderEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      SQFL_EVENT_TYPE( AppRender );
   };

   class SQFL_API AppAfterRenderEvent : public ApplicationEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      AppAfterRenderEvent() : ApplicationEvent() {}

      /*****   CLASS   FUNCTIONS    *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppAfterRenderEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      SQFL_EVENT_TYPE( AppAfterRender );
   };
}