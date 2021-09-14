#pragma once
#include <glm/glm.hpp>

namespace Flare::Rendering
{
   class OrthographicCamera
   {
      /*****   VARIABLES   *****/
      private:
      glm::mat4 m_ProjectionMatrix;
      glm::mat4 m_ViewMatrix;
      glm::mat4 m_ViewProjectionMatrix;

      glm::vec3 m_Position = { 0.0f, 0.0f , 0.0f };
      float m_Rotation = 0.0f;

      /*****  C-TOR D-TOR  *****/
      public:
      OrthographicCamera( float a_Left, float a_Right, float a_Bottom, float a_Top );

      /*****   FUNCTIONS   *****/
      private:
      void UpdateViewMatrix();

      public:
      void SetProjection( float a_Left, float a_Right, float a_Bottom, float a_Top );

      /*****   GETTERS   *****/
      public:
      const glm::vec3& GetPosition() const { return m_Position; }
      const float GetRotation() const { return m_Rotation; }
      const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
      const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
      const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

      /*****   SETTERS   *****/
      public:
      void SetPosition( const glm::vec3& a_Position ) { m_Position = a_Position; UpdateViewMatrix(); }
      void SetRotation( float a_Rotation ) { m_Rotation = a_Rotation; UpdateViewMatrix(); }
   };
}