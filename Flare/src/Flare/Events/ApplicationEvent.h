#pragma once

#include "Event.h"

namespace Flare::Events
{
   class ApplicationEvent : public Event
   {
      /*****  C-TOR D-TOR  *****/
      protected:
      ApplicationEvent() {}

      /*****   GETTERS   *****/
      FLARE_EVENT_CATEGORY( static_cast<uint32_t>(EventCategory::Application) );
   };

   class AppTickEvent : public ApplicationEvent
   {
      /*****  C-TOR D-TOR  *****/
      public:
      AppTickEvent() : ApplicationEvent() {}

      /*****   FUNCTIONS   *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppTickEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      FLARE_EVENT_TYPE( AppTick );
   };

   class AppBeforeUpdateEvent : public ApplicationEvent
   {
      /*****  C-TOR D-TOR  *****/
      public:
      AppBeforeUpdateEvent() : ApplicationEvent() {}

      /*****   FUNCTIONS   *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppBeforeUpdateEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      FLARE_EVENT_TYPE( AppBeforeUpdate );
   };

   class AppUpdateEvent : public ApplicationEvent
   {
      /*****  C-TOR D-TOR  *****/
      public:
      AppUpdateEvent() : ApplicationEvent() {}

      /*****   FUNCTIONS   *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppUpdateEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      FLARE_EVENT_TYPE( AppUpdate );
   };

   class AppAfterUpdateEvent : public ApplicationEvent
   {
      /*****  C-TOR D-TOR  *****/
      public:
      AppAfterUpdateEvent() : ApplicationEvent() {}

      /*****   FUNCTIONS   *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppAfterUpdateEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      FLARE_EVENT_TYPE( AppAfterUpdate );
   };

   class AppBeforeRenderEvent : public ApplicationEvent
   {
      /*****  C-TOR D-TOR  *****/
      public:
      AppBeforeRenderEvent() : ApplicationEvent() {}

      /*****   FUNCTIONS   *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppBeforeRenderEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      FLARE_EVENT_TYPE( AppBeforeRender );
   };

   class AppRenderEvent : public ApplicationEvent
   {
      /*****  C-TOR D-TOR  *****/
      public:
      AppRenderEvent() : ApplicationEvent() {}

      /*****   FUNCTIONS   *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppRenderEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      FLARE_EVENT_TYPE( AppRender );
   };

   class AppAfterRenderEvent : public ApplicationEvent
   {
      /*****  C-TOR D-TOR  *****/
      public:
      AppAfterRenderEvent() : ApplicationEvent() {}

      /*****   FUNCTIONS   *****/
      std::string ToString() const
      {
         std::stringstream x_SS;
         x_SS << "AppAfterRenderEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      FLARE_EVENT_TYPE( AppAfterRender );
   };
}