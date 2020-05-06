#pragma once

#include <functional>

#include "Flare/Core.h"
#include "Flare/Events/Event.h"
#include "Logging/Console.h"

namespace Flare::UserInterface
{
   struct WindowModel
   {
      /*****   CLASS   VARIABLES    *****/
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

   class FLARE_API Window
   {
      public:
      using EventCallback = std::function<void( Flare::Events::Event& )>;

      /*****   CLASS   VARIABLES    *****/
      protected:
      Logging::Logger* m_WindowLogger;

      /*****   CLASS   C-TOR D-TOR  *****/
      public:
      virtual ~Window() {}

      /*****   CLASS   FUNCTIONS    *****/
      public:
      static Window* Create( const WindowModel& a_Model = WindowModel() );
      virtual void OnUpdate() = 0;

      /*****   SETTERS   *****/
      public:
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