#pragma once

#include "Event.h"

namespace SquareFlare::Events
{
   class SQFL_API KeyEvent : public Event
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      int m_KeyCode;

      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      KeyEvent( int a_KeyCode ) :
         m_KeyCode( a_KeyCode )
      {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      SQFL_EVENT_CATEGORY( EventCategory::Keyboard | EventCategory::Input );

      /*****   GETTERS   *****/
      public:
      inline int GetKeyCode() const
      {
         return m_KeyCode;
      }
   };

   class SQFL_API KeyPressedEvent : public KeyEvent
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      int m_RepeatCount;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      KeyPressedEvent( int a_KeyCode, int a_RepeatCount ) :
         KeyEvent( a_KeyCode ),
         m_RepeatCount( a_RepeatCount )
      {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "KeyPressedEvent: " << m_KeyCode << " - Rep " << m_RepeatCount;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      SQFL_EVENT_TYPE( KeyPressed );
      inline int GetRepeatCount() const
      {
         return m_RepeatCount;
      }
   };

   class SQFL_API KeyReleasedEvent : public KeyEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      KeyReleasedEvent( int a_KeyCode) :
         KeyEvent( a_KeyCode )
      {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "KeyReleasedEvent: " << m_KeyCode;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      SQFL_EVENT_TYPE( KeyReleased );
   };
}
