#pragma once
#include "Flare/Time/TimeStep.h"
#include "Flare/Events/Event.h"
#include "Flare/Events/MouseEvent.h"
#include "Flare/Events/WindowEvent.h"

#include <glm/glm.hpp>

namespace Flare::Rendering
{
   class CameraController
   {
      /*****   VARIABLES   *****/
      protected:
      float m_AspectRatio;
      glm::vec3 m_CameraPosition = glm::vec3( 0.0f, 0.0f, 0.0f );
      float m_CameraTranslationSpeed = 5.0f;
      float m_CameraRotation = 0.0f;
      float m_CameraRotationSpeed = 120.0f;
      float m_Zoom = 1.0f;

      /*****  C-TOR D-TOR  *****/
      public:
      CameraController() = delete;
      CameraController( float a_AspectRatio );
      CameraController( float a_Width, float a_Height );

      /*****   FUNCTIONS   *****/
      public:
      virtual void OnUpdate( Time::TimeStep a_TimeStep ) = 0;

      /*****   EVENT HANDLERS   *****/
      public:
      virtual void OnEvent( Events::Event& a_Event ) = 0;

      protected:
      virtual bool OnMouseScrolled(Events::MouseScrolledEvent& a_Event) = 0;
      virtual bool OnWindowResized(Events::WindowResizeEvent& a_Event) = 0;

      /*****   GETTERS   *****/
      public:
      inline const float GetAspectRatio() const { return m_AspectRatio; }
      inline const glm::vec3& GetPosition() const { return m_CameraPosition; }
      inline const float GetRotation() const { return m_CameraRotation; }
   };
}