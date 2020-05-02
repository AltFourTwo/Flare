#pragma once

#include "Event.h"

#include <functional>
#include <type_traits>

#if 0
#define INTELLISENSE_TEMPLATE_HELPER
#endif

#ifdef INTELLISENSE_TEMPLATE_HELPER
#include "ApplicationEvent.h"
#include "WindowEvent.h"
#include "MouseEvent.h"
#include "KeyEvent.h"
namespace _Ev = ::SquareFlare::Events;
#endif // INTELLISENSE_TEMPLATE_HELPER

namespace SquareFlare::Events
{
   class EventDispatcher
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      Event& m_Event;

      /*****   CLASS   C-TOR D-TOR  *****/
      EventDispatcher( Event& a_Event ) :
         m_Event( a_Event )
      {}

      /*****   CLASS   FUNCTIONS    *****/
      template<typename T, typename = std::enable_if_t<std::is_convertible_v<T*, Event*>>>
      bool Dispatch( std::function<bool( T& )> a_HandlerFunction )
      {
         // Play with Event Interceptors here ?
         if ( m_Event.GetEventType() == T::GetStaticType() )
         {
            m_Event.m_Handled = a_HandlerFunction(*(T*)&m_Event);
            return true;
         }
         return false;
      }
   };
}