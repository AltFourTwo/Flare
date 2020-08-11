#pragma once

#include "Flare/UserInput/Input.h"

namespace Flare::UserInput
{
   class WindowsInput : public Input
   {
      friend class Input;

      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      WindowsInput( KeyMap&& a_KeyMap ) :
         Input( std::move( a_KeyMap ) )
      {};

      /*****   CLASS   FUNCTIONS    *****/
      protected:
      virtual bool IsKeyPressed_I( int a_Keycode ) const override;
      virtual bool IsMouseButtonPressed_I( int a_Button ) const override;
      virtual Input::MousePosition GetMousePosition_I() const override;
      virtual float GetMouseX_I() const override;
      virtual float GetMouseY_I() const override;
   };
}
