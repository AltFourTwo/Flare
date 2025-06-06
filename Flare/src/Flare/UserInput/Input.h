#pragma once

#include "Flare/Core/Core.h"
#include "Flare/UserInput/InputMaps.h"
#include "Platforms/Utils/PlatformUtils.h"

namespace Flare::UserInput
{
   class Input;
   template<typename T>
   concept DerivedFromInput = std::derived_from<T, Input>;

   class Input
   {
      public:
      using MousePosition = std::pair<float, float>;

      /*****   VARIABLES   *****/
      private:
      static Input* s_Instance;
      const KeyMap m_KeyMap;
      const ModifierMap m_ModifierMap;
      const MouseMap m_MouseMap;
      const JoystickMap m_JoystickMap;
      const GamePadMap m_GamePadMap;
      const GamePadAxisMap m_GamePadAxisMap;

      /*****  C-TOR D-TOR  *****/
      protected:
      Input( KeyMap&& a_KeyMap, ModifierMap&& a_ModifierMap, MouseMap&& a_MouseMap, JoystickMap&& a_JoystickMap, GamePadMap&& a_GamePadMap, GamePadAxisMap&& a_GamePadAxisMap ) :
         m_KeyMap( std::move( a_KeyMap ) ),
         m_ModifierMap( std::move( a_ModifierMap ) ),
         m_MouseMap( std::move( a_MouseMap ) ),
         m_JoystickMap( std::move( a_JoystickMap ) ),
         m_GamePadMap( std::move( a_GamePadMap ) ),
         m_GamePadAxisMap( std::move( a_GamePadAxisMap ) )
      {}

      /*****   FUNCTIONS   *****/
      protected:
      virtual bool IsKeyPressed_I( int a_Keycode ) const = 0;
      virtual MousePosition GetMousePosition_I() const = 0;
      virtual bool IsMouseButtonPressed_I( int a_Button ) const = 0;
      virtual float GetMouseX_I() const = 0;
      virtual float GetMouseY_I() const = 0;

      public:
      template<typename T> requires DerivedFromInput<T>
      static bool Initialize( Flare::Rendering::API a_API )
      {
         if ( s_Instance )
            return false;

         s_Instance = new T(
            std::move( Flare::UserInput::GetAPIKeyMap( a_API ) ),
            std::move( Flare::UserInput::GetAPIModifierMap( a_API ) ),
            std::move( Flare::UserInput::GetAPIMouseMap( a_API ) ),
            std::move( Flare::UserInput::GetAPIJoystickMap( a_API ) ),
            std::move( Flare::UserInput::GetAPIGamePadMap( a_API ) ),
            std::move( Flare::UserInput::GetAPIGamePadAxisMap( a_API ) )
         );

         return true;
      }

      inline static Input& GetInstance()
      {
         return *s_Instance;
      }

      inline static bool IsKeyPressed( const int a_Keycode )
      {
         return s_Instance->IsKeyPressed_I( s_Instance->m_KeyMap[a_Keycode] );
      }

      inline static bool IsMouseButtonPressed( int a_Button )
      {
         return s_Instance->IsMouseButtonPressed_I( s_Instance->m_MouseMap[a_Button] );
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

      /*****   OPERATORS    *****/
      public:
      const int& operator[] ( const int a_Index ) const { return m_KeyMap[a_Index]; }
   };
}