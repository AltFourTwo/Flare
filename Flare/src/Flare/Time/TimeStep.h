#pragma once

namespace Flare::Time
{
   class TimeStep
   {
      /*****   VARIABLES   *****/
      private:
      float m_Time;

      /*****  C-TOR D-TOR  *****/
      public:
      TimeStep( float a_Time = 0.0f )
         : m_Time( a_Time )
      {}

      /*****   FUNCTIONS   *****/
      public:
      inline float GetSeconds() const { return m_Time; }
      inline float GetMilliseconds() const { return m_Time * 1000.0f; }

      /*****   OPERATORS    *****/
      public:
      operator float() const { return m_Time; } // TODO Documentation : The default return value is in seconds.
   };
}

