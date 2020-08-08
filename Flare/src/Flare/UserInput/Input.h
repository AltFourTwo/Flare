#pragma once

#include "Flare/Core.h"

namespace Flare::UserInput
{
   class FLARE_API Input
   {
      public:
      using MousePosition = std::pair<float ,float>;

      /*****   CLASS   VARIABLES    *****/
      private:
      static Input* s_Instance;

      /*****   CLASS   FUNCTIONS    *****/
      public:
      inline static bool IsKeyPressed( int a_Keycode )
      {
         return s_Instance->IsKeyPressed_I( a_Keycode );
      }

      inline static bool IsMouseButtonPressed( int a_Button )
      {
         return s_Instance->IsMouseButtonPressed_I( a_Button );
      }

      inline static std::pair<float, float> GetMousePosition()
      {
         return s_Instance->GetMousePosition_I();
      }

      inline static float GetMouseX()
      {
         return s_Instance->GetMouseX_I();
      }

      inline static float GetMouseY()
      {
         return s_Instance->GetMouseY_I();
      }

      protected:
      virtual bool IsKeyPressed_I( int a_Keycode ) = 0;
      virtual MousePosition GetMousePosition_I() = 0;
      virtual bool IsMouseButtonPressed_I( int a_Button ) = 0;
      virtual float GetMouseX_I() = 0;
      virtual float GetMouseY_I() = 0;
   };
}