#pragma once

#include "Flare/UserInput/Input.h"

namespace Flare::UserInput
{
   class WindowsInput : public Input
   {
      /*****   CLASS   FUNCTIONS    *****/
      protected:
      virtual bool IsKeyPressed_I(int a_Keycode) override;
      virtual bool IsMouseButtonPressed_I( int a_Button ) override;
      virtual Input::MousePosition GetMousePosition_I() override;
      virtual float GetMouseX_I() override;
      virtual float GetMouseY_I() override;
   };
}

