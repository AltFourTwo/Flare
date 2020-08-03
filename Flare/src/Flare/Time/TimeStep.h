#pragma once

namespace Flare::Time
{
   class TimeStep
   {
      /*****   CLASS   VARIABLES    *****/
      private:
      float m_Time;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      TimeStep( float a_Time = 0.0f )
         : m_Time( a_Time )
      {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      float GetSeconds() const { return m_Time; }
      float GetMilliseconds() const { return m_Time * 1000.0f; }

      /*****   CLASS   OPERATORS    *****/
      public:
      operator float() const { return m_Time; } // TODO Documentation : The default return value is in seconds.
   };
}

