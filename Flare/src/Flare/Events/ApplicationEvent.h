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
      virtual uint32_t GetCategoryFlags() const override { return static_cast<uint32_t>( EventCategory::Application ); }
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
      static EventType GetStaticType() { return EventType::AppTick; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "AppTick"; }
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
      static EventType GetStaticType() { return EventType::AppUpdate; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "AppUpdate"; }
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
      static EventType GetStaticType() { return EventType::AppRender; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "AppRender"; }
   };
}