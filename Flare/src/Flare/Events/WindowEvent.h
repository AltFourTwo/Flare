#pragma once

#include "Event.h"

namespace Flare::Events
{
   class FLARE_API WindowCloseEvent : public Event
   {
      /*****   CLASS   FUNCTIONS    *****/
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
      FLARE_EVENT_CATEGORY( EventCategory::Window );
   };

   class FLARE_API WindowResizeEvent : public Event
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      unsigned int m_Width, m_Height;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      WindowResizeEvent(unsigned int a_Width, unsigned int a_Height ) :
         m_Width( a_Width ),
         m_Height( a_Height )
      {}

      /*****   CLASS   FUNCTIONS    *****/
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
      FLARE_EVENT_CATEGORY( EventCategory::Window );
   };

   class FLARE_API WindowFocusEvent : public Event
   {
      /*****   CLASS   FUNCTIONS    *****/
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
      FLARE_EVENT_CATEGORY( EventCategory::Window );
   };

   class FLARE_API WindowLostFocusEvent : public Event
   {
      /*****   CLASS   FUNCTIONS    *****/
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
      FLARE_EVENT_CATEGORY( EventCategory::Window );
   };

   class FLARE_API WindowMovedEvent : public Event
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      int m_XPos, m_YPos;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      WindowMovedEvent(int a_XPos, int a_YPos) :
         m_XPos(a_XPos),
         m_YPos(a_YPos)
      {}

      /*****   CLASS   FUNCTIONS    *****/
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
      FLARE_EVENT_CATEGORY( EventCategory::Window );
   };
}