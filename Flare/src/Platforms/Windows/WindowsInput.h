#pragma once

#include "Flare/UserInterface/Input.h"

namespace Flare::UserInterface
{
   class WindowsInput : public Input
   {
      /*****   CLASS   FUNCTIONS    *****/
      protected:
      virtual bool IsKeyPressed_I(int a_Keycode) override;
      virtual bool IsMouseButtonPressed_I( int a_Button ) override;
      virtual std::pair<float, float> GetMousePosition_I() override;
      virtual float GetMouseX_I() override;
      virtual float GetMouseY_I() override;
   };
}

