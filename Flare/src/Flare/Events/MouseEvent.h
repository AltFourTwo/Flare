#pragma once

#include "Event.h"

namespace Flare::Events
{
   class MouseEvent : public Event
   {
      /*****   GETTERS   *****/
      public:
      virtual uint32_t GetCategoryFlags() const override { return static_cast<uint32_t>( EventCategory::Mouse ); }
   };

   class MouseMovedEvent : public MouseEvent
   {
      /*****   VARIABLES   *****/
      private:
      float m_MouseX, m_MouseY;

      /*****  C-TOR D-TOR  *****/
      public:
      MouseMovedEvent( float a_XPos, float a_YPos ) :
         m_MouseX( a_XPos ),
         m_MouseY( a_YPos )
      {}

      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      inline float GetX() const { return m_MouseX; }
      inline float GetY() const { return m_MouseY; }
      static EventType GetStaticType() { return EventType::MouseMoved; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "MouseMoved"; }
      
   };

   class MouseScrolledEvent : public MouseEvent
   {
      /*****   VARIABLES   *****/
      private:
      float m_XOffset, m_YOffset;

      /*****  C-TOR D-TOR  *****/
      public:
      MouseScrolledEvent( float a_XOffset, float a_YOffset ) :
         m_XOffset( a_XOffset ),
         m_YOffset( a_YOffset )
      {}

      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      inline float GetXOffSet() const { return m_XOffset; }
      inline float GetYOffSet() const { return m_YOffset; }
      static EventType GetStaticType() { return EventType::MouseScrolled; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "MouseScrolled"; }
   };

   class MouseButtonEvent : public MouseEvent
   {
      /*****   VARIABLES   *****/
      protected:
      int m_Button;

      /*****  C-TOR D-TOR  *****/
      protected:
      MouseButtonEvent( int a_Button ) :
         m_Button( a_Button )
      {}

      /*****   GETTERS   *****/
      public:
      inline int GetMouseButton() const { return m_Button; }
   };

   class MouseButtonPressedEvent : public MouseButtonEvent
   {
      /*****  C-TOR D-TOR  *****/
      public:
      MouseButtonPressedEvent( int a_Button ) :
         MouseButtonEvent( a_Button )
      {}

      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "MouseButtonPressedEvent: " << m_Button;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      static EventType GetStaticType() { return EventType::MouseButtonPressed; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "MouseButtonPressed"; }
   };

   class MouseButtonReleasedEvent : public MouseButtonEvent
   {
      /*****  C-TOR D-TOR  *****/
      public:
      MouseButtonReleasedEvent( int a_Button ) :
         MouseButtonEvent( a_Button )
      {}

      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "MouseButtonReleasedEvent: " << m_Button;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      static EventType GetStaticType() { return EventType::MouseButtonReleased; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "MouseButtonReleased"; }
   };
}