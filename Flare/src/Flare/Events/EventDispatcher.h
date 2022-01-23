#pragma once

#include "Flare/Events/Event.h"

namespace Flare::Events
{
   template<typename T>
   concept DerivedFromEvent = std::derived_from<T, Event>;

   class EventDispatcher
   {
      /*****   VARIABLES   *****/
      private:
      Event& m_Event;

      /*****  C-TOR D-TOR  *****/
      public:
      EventDispatcher( Event& a_Event ) :
         m_Event( a_Event )
      {}

      /*****   FUNCTIONS   *****/
      public:
      // F is deduced by the compiler.
      template<typename T, typename F> requires DerivedFromEvent<T>
      bool Dispatch( const F& a_HandlerFunction )
      {
         // Play with Event Interceptors here ?
         if ( m_Event.GetEventType() == T::GetStaticType() )
         {
            m_Event.m_Handled |= a_HandlerFunction( static_cast<T&>( m_Event ) );
            return true;
         }
         return false;
      }
   };
}