#pragma once

#include "Event.h"

namespace Flare::Events
{
   class FLARE_API MouseMovedEvent : public Event
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      float m_MouseX, m_MouseY;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      MouseMovedEvent( float a_XPos, float a_YPos ) :
         m_MouseX( a_XPos ),
         m_MouseY( a_YPos )
      {}

      /*****   CLASS   FUNCTIONS    *****/
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
      FLARE_EVENT_TYPE( MouseMoved );
      FLARE_EVENT_CATEGORY( EventCategory::Mouse | EventCategory::Input );
   };

   class FLARE_API MouseScrolledEvent : public Event
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      float m_XOffset, m_YOffset;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      MouseScrolledEvent( float a_XOffset, float a_YOffset ) :
         m_XOffset( a_XOffset ),
         m_YOffset( a_YOffset )
      {}

      /*****   CLASS   FUNCTIONS    *****/
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
      FLARE_EVENT_TYPE( MouseScrolled );
      FLARE_EVENT_CATEGORY( EventCategory::Mouse | EventCategory::Input );
   };

   class FLARE_API MouseButtonEvent : public Event
   {
      /*****   CLASS   VARIABLES    *****/
      protected:
      int m_Button;

      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      MouseButtonEvent( int a_Button ) :
         m_Button( a_Button )
      {}

      /*****   GETTERS   *****/
      public:
      inline int GetMouseButton() const { return m_Button; }
      FLARE_EVENT_CATEGORY( EventCategory::MouseButton | EventCategory::Mouse | EventCategory::Input );
   };

   class FLARE_API MouseButtonPressedEvent : public MouseButtonEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      MouseButtonPressedEvent( int a_Button ) :
         MouseButtonEvent( a_Button )
      {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "MouseButtonPressedEvent: " << m_Button;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      FLARE_EVENT_TYPE( MouseButtonPressed );
   };

   class FLARE_API MouseButtonReleasedEvent : public MouseButtonEvent
   {
      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      MouseButtonReleasedEvent( int a_Button ) :
         MouseButtonEvent( a_Button )
      {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "MouseButtonReleasedEvent: " << m_Button;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      public:
      FLARE_EVENT_TYPE( MouseButtonReleased );
   };
}