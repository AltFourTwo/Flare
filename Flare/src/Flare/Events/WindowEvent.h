#pragma once

#include "Event.h"

namespace Flare::Events
{
   class WindowCloseEvent : public Event
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
      FLARE_EVENT_TYPE( WindowClose );
      FLARE_EVENT_CATEGORY( static_cast<uint32_t>( EventCategory::Window) );
   };

   class WindowResizeEvent : public Event
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
      FLARE_EVENT_TYPE( WindowResize );
      FLARE_EVENT_CATEGORY( static_cast<uint32_t>( EventCategory::Window) );
   };

   class WindowFocusEvent : public Event
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
      FLARE_EVENT_TYPE( WindowFocus );
      FLARE_EVENT_CATEGORY( static_cast<uint32_t>( EventCategory::Window) );
   };

   class WindowLostFocusEvent : public Event
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
      FLARE_EVENT_TYPE( WindowLostFocus );
      FLARE_EVENT_CATEGORY( static_cast<uint32_t>( EventCategory::Window) );
   };

   class WindowMovedEvent : public Event
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
      FLARE_EVENT_TYPE( WindowMoved );
      FLARE_EVENT_CATEGORY( static_cast<uint32_t>( EventCategory::Window) );
   };
}