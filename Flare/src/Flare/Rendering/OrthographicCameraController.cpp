#include "FlarePCH.h"
#include "OrthographicCameraController.h"

#include "Flare/Core.h"
#include "Flare/UserInput/Input.h"
#include "Flare/Events/EventDispatcher.h"

namespace Flare::Rendering
{
   /*****  C-TOR D-TOR  *****/
   OrthographicCameraController::OrthographicCameraController( float a_AspectRatio, bool a_RotationEnabled ) :
      CameraController( a_AspectRatio ),
      m_Camera( -m_AspectRatio * m_Zoom, m_AspectRatio* m_Zoom, -m_Zoom, m_Zoom ),
      m_RotationEnabled( a_RotationEnabled )
   {}

   OrthographicCameraController::OrthographicCameraController( float a_Width, float a_Height, bool a_RotationEnabled ) :
      CameraController( a_Width, a_Height ),
      m_Camera( -m_AspectRatio * m_Zoom, m_AspectRatio* m_Zoom, -m_Zoom, m_Zoom ),
      m_RotationEnabled( a_RotationEnabled )
   {}

   /*****   FUNCTIONS   *****/
   void OrthographicCameraController::OnUpdate( Time::TimeStep a_TimeStep )
   {
      UserInput::Input& x_Input = UserInput::Input::GetInstance();

      // TODO : Camera translation speed could be dynamic depending on zoom.
      if ( x_Input.IsKeyPressed( FLARE_KEY_A ) )
         m_CameraPosition.x -= m_CameraTranslationSpeed * a_TimeStep.GetSeconds();
      else if ( x_Input.IsKeyPressed( FLARE_KEY_D ) )
         m_CameraPosition.x += m_CameraTranslationSpeed * a_TimeStep.GetSeconds();

      if ( x_Input.IsKeyPressed( FLARE_KEY_W ) )
         m_CameraPosition.y += m_CameraTranslationSpeed * a_TimeStep.GetSeconds();
      else if ( x_Input.IsKeyPressed( FLARE_KEY_S ) )
         m_CameraPosition.y -= m_CameraTranslationSpeed * a_TimeStep.GetSeconds();

      m_Camera.SetPosition(m_CameraPosition);

      if ( m_RotationEnabled )
      {
         if ( x_Input.IsKeyPressed( FLARE_KEY_Q ) )
            m_CameraRotation += m_CameraRotationSpeed * a_TimeStep.GetSeconds();
         else if ( x_Input.IsKeyPressed( FLARE_KEY_E ) )
            m_CameraRotation -= m_CameraRotationSpeed * a_TimeStep.GetSeconds();

         m_Camera.SetRotation(m_CameraRotation);
      }
   }

   /*****   EVENT HANDLERS   *****/
   void OrthographicCameraController::OnEvent( Events::Event& a_Event )
   {
      Events::EventDispatcher x_Dispatcher( a_Event );
      x_Dispatcher.Dispatch<Events::MouseScrolledEvent>( FLARE_BIND_EVENT_FN( OrthographicCameraController::OnMouseScrolled ) );
      x_Dispatcher.Dispatch<Events::WindowResizeEvent>( FLARE_BIND_EVENT_FN( OrthographicCameraController::OnWindowResized ) );
   }

   bool OrthographicCameraController::OnMouseScrolled( Events::MouseScrolledEvent& a_Event )
   {
      m_Zoom -= a_Event.GetYOffSet();
      m_Camera.SetProjection( -m_AspectRatio * m_Zoom, m_AspectRatio * m_Zoom, -m_Zoom, m_Zoom );
      return false;
   }

   bool OrthographicCameraController::OnWindowResized( Events::WindowResizeEvent& a_Event )
   {
      m_AspectRatio = (float)a_Event.GetWidth() / (float)a_Event.GetHeight();
      m_Camera.SetProjection( -m_AspectRatio * m_Zoom, m_AspectRatio * m_Zoom, -m_Zoom, m_Zoom );
      return false;
   }
}
