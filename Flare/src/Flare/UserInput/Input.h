#pragma once

#include "Flare/Core.h"
#include "Templates/BaseTemplates.h"
#include "InputMaps.h"

namespace Flare::UserInput
{
   class FLARE_API Input
   {
      public:
      using MousePosition = std::pair<float, float>;

      /*****   CLASS   VARIABLES    *****/
      private:
      static Input* s_Instance;
      const KeyMap m_KeyMap;

      /*****   CLASS   C-TOR D-TOR  *****/
      protected:
      Input( KeyMap&& a_KeyMap ) :
         m_KeyMap( std::move( a_KeyMap ) )
      {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      template<typename T, typename U, typename = Utility::Templates::EnableByInheritance<T, Input>, typename = Utility::Templates::EnableByInheritance<U, KeyMap>>
      inline static bool Initialize( U&& a_KeyMap )
      {
         if ( s_Instance )
            return false;

         s_Instance = new T( std::forward<KeyMap>( a_KeyMap ) );

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
      virtual bool IsKeyPressed_I( int a_Keycode ) const = 0;
      virtual MousePosition GetMousePosition_I() const = 0;
      virtual bool IsMouseButtonPressed_I( int a_Button ) const = 0;
      virtual float GetMouseX_I() const = 0;
      virtual float GetMouseY_I() const = 0;
      
      /*****   CLASS   OPERATORS    *****/
      public:
      const int& operator[] ( const int a_Index ) const { return m_KeyMap[a_Index]; }
   };
}