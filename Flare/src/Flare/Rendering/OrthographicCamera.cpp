#include "FlarePCH.h"
#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Flare::Rendering
{
   /*****   CLASS   C-TOR D-TOR  *****/
   OrthographicCamera::OrthographicCamera( float a_Left, float a_Right, float a_Bottom, float a_Top ) :
      m_ProjectionMatrix( glm::ortho( a_Left, a_Right, a_Bottom, a_Top, -1.0f, 1.0f ) ),
      m_ViewMatrix( 1.0f )
   {
      m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix; // Glm is Column-major.
   }

   /*****   CLASS   FUNCTIONS    *****/
   void OrthographicCamera::UpdateViewMatrix()
   {
      glm::mat4 x_TransformationMatrix = // Translate then rotate.
         glm::translate( glm::mat4( 1.0f ), m_Position ) *
         glm::rotate( glm::mat4( 1.0f ), glm::radians( m_Rotation ), glm::vec3( 0, 0, 1 ) );

      m_ViewMatrix = glm::inverse( x_TransformationMatrix );
      m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix; // Glm is Column-major.
   }
}