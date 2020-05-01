#pragma once

#include "Event.h"

namespace SquareFlare::Events
{

   class SQFL_API WindowCloseEvent : public Event
   {
      /*****   CLASS   FUNCTIONS    *****/
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "WindowCloseEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      SQFL_EVENT_TYPE( WindowClose );
      SQFL_EVENT_CATEGORY( EventCategory::Window );
   };

   class SQFL_API WindowResizeEvent : public Event
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
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "WindowResizeEvent: " << m_Width << ", " << m_Height;
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      SQFL_EVENT_TYPE( WindowResize );
      SQFL_EVENT_CATEGORY( EventCategory::Window );

      inline unsigned int GetWidth() const
      {
         return m_Width;
      }

      inline unsigned int GetHeight() const
      {
         return m_Height;
      }
   };

   class SQFL_API WindowFocusEvent : public Event
   {
      /*****   CLASS   FUNCTIONS    *****/
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "WindowFocusEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      SQFL_EVENT_TYPE( WindowFocus );
      SQFL_EVENT_CATEGORY( EventCategory::Window );
   };

   class SQFL_API WindowLostFocusEvent : public Event
   {
      /*****   CLASS   FUNCTIONS    *****/
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "WindowLostFocusEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      SQFL_EVENT_TYPE( WindowLostFocus );
   };

   class SQFL_API WindowMovedEvent : public Event
   {
      /*****   CLASS   VARIABLES    *****/
      unsigned int m_XPos, m_YPos;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      WindowMovedEvent(int a_XPos, int a_YPos) {}

      /*****   CLASS   FUNCTIONS    *****/
      std::string ToString() const override
      {
         std::stringstream x_SS;
         x_SS << "WindowMovedEvent";
         return x_SS.str();
      }

      /*****   GETTERS   *****/
      SQFL_EVENT_TYPE( WindowMoved );
   };
}