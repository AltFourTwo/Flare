#pragma once

#include "Event.h"

namespace Flare::Events
{
   class WindowEvent : public Event
   {
      /*****   GETTERS   *****/
      public:
      virtual uint32_t GetCategoryFlags() const override { return static_cast<uint32_t>( EventCategory::Window ); }
   };

   class WindowCloseEvent : public WindowEvent
   {
      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "WindowCloseEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      static EventType GetStaticType() { return EventType::WindowClose; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "WindowClose"; }
   };

   class WindowResizeEvent : public WindowEvent
   {
      /*****   VARIABLES   *****/
      private:
      unsigned int m_Width, m_Height;

      /*****  C-TOR D-TOR  *****/
      public:
      WindowResizeEvent(unsigned int a_Width, unsigned int a_Height ) :
         m_Width( a_Width ),
         m_Height( a_Height )
      {}

      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "WindowResizeEvent: " << m_Width << ", " << m_Height;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      inline unsigned int GetWidth() const { return m_Width; }
      inline unsigned int GetHeight() const { return m_Height; }
      static EventType GetStaticType() { return EventType::WindowResize; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "WindowResize"; }
   };

   class WindowFocusEvent : public WindowEvent
   {
      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "WindowFocusEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      static EventType GetStaticType() { return EventType::WindowFocus; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "WindowFocus"; }
   };

   class WindowLostFocusEvent : public WindowEvent
   {
      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "WindowLostFocusEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      static EventType GetStaticType() { return EventType::WindowLostFocus; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "WindowLostFocus"; }
   };

   class WindowMovedEvent : public WindowEvent
   {
      /*****   VARIABLES   *****/
      private:
      int m_XPos, m_YPos;

      /*****  C-TOR D-TOR  *****/
      public:
      WindowMovedEvent(int a_XPos, int a_YPos) :
         m_XPos(a_XPos),
         m_YPos(a_YPos)
      {}

      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "WindowMovedEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      inline int GetX() const { return m_XPos; }
      inline int GetY() const { return m_YPos; }
      static EventType GetStaticType() { return EventType::WindowMoved; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "WindowMoved"; }
   };
}