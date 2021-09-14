#pragma once
#include "CameraController.h"
#include "OrthographicCamera.h"

namespace Flare::Rendering
{
   class OrthographicCameraController : public CameraController
   {
      /*****   VARIABLES   *****/
      private:
      OrthographicCamera m_Camera;
      bool m_RotationEnabled;

      /*****  C-TOR D-TOR  *****/
      public:
      OrthographicCameraController() = delete;
      OrthographicCameraController( float a_AspectRatio, bool a_RotationEnabled = false );
      OrthographicCameraController( float a_Width, float a_Height, bool a_RotationEnabled = false );

      /*****   FUNCTIONS   *****/
      public:
      virtual void OnUpdate( Time::TimeStep a_TimeStep ) override;

      /*****   EVENT HANDLERS   *****/
      public:
      virtual void OnEvent( Events::Event& a_Event ) override;

      protected:
      virtual bool OnMouseScrolled( Events::MouseScrolledEvent& a_Event ) override;
      virtual bool OnWindowResized( Events::WindowResizeEvent& a_Event ) override;

      /*****   GETTERS   *****/
      public:
      inline OrthographicCamera& GetCamera() { return m_Camera; }
      inline const OrthographicCamera& GetCamera() const { return m_Camera; }
   };
}