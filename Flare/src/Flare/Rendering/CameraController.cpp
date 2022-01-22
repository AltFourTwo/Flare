#include "FlarePCH.h"
#include "CameraController.h"

#include "Flare/Events/EventDispatcher.h"
#include "Flare/Events/MouseEvent.h"
#include "Flare/Events/WindowEvent.h"

namespace Flare::Rendering
{
   /*****  C-TOR D-TOR  *****/
   CameraController::CameraController( float a_AspectRatio ) :
      m_AspectRatio( a_AspectRatio )
   {
      // TODO : Log Negative
   }

   CameraController::CameraController( float a_Width, float a_Height ) :
      m_AspectRatio( a_Width / a_Height )
   {
      // TODO : Log Negative
   }
}