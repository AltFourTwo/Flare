#pragma once

#include "Flare/UserInput/Input.h"

namespace Flare::UserInput
{
   class WindowsInput : public Input
   {
      friend class Input;

      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      WindowsInput( KeyMap&& a_KeyMap, ModifierMap&& a_ModifierMap, MouseMap&& a_MouseMap, JoystickMap&& a_JoystickMap, GamePadMap&& a_GamePadMap, GamePadAxisMap&& a_GamePadAxisMap ) :
         Input( std::move( a_KeyMap ), std::move( a_ModifierMap ), std::move( a_MouseMap ), std::move( a_JoystickMap ), std::move( a_GamePadMap ), std::move( a_GamePadAxisMap ) )
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
