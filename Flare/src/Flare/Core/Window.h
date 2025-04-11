#pragma once

#include <functional>

#include "Flare/Core/Core.h"
#include "Flare/Events/Event.h"
#include "Flare/UserInput/Input.h"

namespace Flare::UserInterface
{
   struct WindowModel
   {
      /*****   VARIABLES   *****/
      std::string Title;
      unsigned int Width;
      unsigned int Height;

      WindowModel( const std::string& a_Title = "Flare",
                   unsigned int a_Width = 1280,
                   unsigned int a_Height = 720 ) :
         Title( a_Title ),
         Width( a_Width ),
         Height( a_Height )
      {}
   };

   class Window
   {
      public:
      using EventCallback = std::function<void( Flare::Events::Event& )>;

      /*****   VARIABLES   *****/
      protected:
      const UserInput::Input* m_InputScheme = nullptr;

      /*****  C-TOR D-TOR  *****/
      public:
      Window() {}

      virtual ~Window() {}

      /*****   FUNCTIONS   *****/
      public:
      static Window* Create( const bool a_VSync = false, const WindowModel& a_Model = WindowModel() );
      virtual void OnUpdate() = 0;
      virtual void OnRender() = 0;

      /*****   SETTERS   *****/
      public:
      virtual void SetInputScheme( const UserInput::Input& a_InputScheme ) { m_InputScheme = &a_InputScheme; }
      virtual void SetEventCallback( const EventCallback& a_Callback ) = 0;
      virtual void SetVSync( bool a_Value ) = 0;

      /*****   GETTERS   *****/
      public:
      virtual void* GetNativeWindow() const = 0;
      virtual unsigned int GetWidth() const = 0;
      virtual unsigned int GetHeight() const = 0;
      virtual bool IsVSync() const = 0;
   };
}