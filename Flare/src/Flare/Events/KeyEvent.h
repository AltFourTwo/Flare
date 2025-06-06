#pragma once

#include "Event.h"

namespace Flare::Events
{
   class KeyEvent : public Event
   {
      /*****   VARIABLES   *****/
      protected:
      int m_KeyCode;

      /*****  C-TOR D-TOR  *****/
      protected:
      KeyEvent( int a_KeyCode ) :
         m_KeyCode( a_KeyCode )
      {}

      /*****   GETTERS   *****/
      public:
      inline int GetKeyCode() const { return m_KeyCode; }
      virtual uint32_t GetCategoryFlags() const override { return static_cast<uint32_t>( EventCategory::Keyboard ); }
   };

   class KeyPressedEvent : public KeyEvent
   {
      /*****   VARIABLES   *****/
      private:
      int m_RepeatCount;

      /*****  C-TOR D-TOR  *****/
      public:
      KeyPressedEvent( int a_KeyCode, int a_RepeatCount ) :
         KeyEvent( a_KeyCode ),
         m_RepeatCount( a_RepeatCount )
      {}

      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "KeyPressedEvent: " << m_KeyCode << " - Rep " << m_RepeatCount;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      inline int GetRepeatCount() const { return m_RepeatCount; }
      static EventType GetStaticType() { return EventType::KeyPressed; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "KeyPressed"; }
   };

   class KeyReleasedEvent : public KeyEvent
   {
      /*****  C-TOR D-TOR  *****/
      public:
      KeyReleasedEvent( int a_KeyCode ) :
         KeyEvent( a_KeyCode )
      {}

      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "KeyReleasedEvent: " << m_KeyCode;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      static EventType GetStaticType() { return EventType::KeyReleased; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "KeyReleased"; }
   };

   class KeyTypedEvent : public KeyEvent
   {
      /*****  C-TOR D-TOR  *****/
      public:
      KeyTypedEvent( int a_KeyCode ) :
         KeyEvent( a_KeyCode )
      {}

      /*****   FUNCTIONS   *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "KeyTypedEvent: " << m_KeyCode;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      static EventType GetStaticType() { return EventType::KeyTyped; }
      virtual EventType GetEventType() const override { return GetStaticType(); }
      virtual const char* GetName() const override { return "KeyTyped"; }
   };
}
