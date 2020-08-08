#include "FlarePCH.h"

#include "Flare/Application.h"
#include "WindowsInput.h"

#include <GLFW/glfw3.h>

namespace Flare::UserInput
{
   Input* Input::s_Instance = new WindowsInput();

   bool WindowsInput::IsKeyPressed_I( int a_Keycode )
   {
      GLFWwindow* x_Window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
      int state = glfwGetKey( x_Window , a_Keycode );
      return state == GLFW_PRESS || state == GLFW_REPEAT;
   }

   bool WindowsInput::IsMouseButtonPressed_I( int a_Button )
   {
      GLFWwindow* x_Window = static_cast<GLFWwindow*>( Application::GetInstance().GetWindow().GetNativeWindow() );
      int state = glfwGetMouseButton( x_Window , a_Button );
      return state == GLFW_PRESS;
   }

   Input::MousePosition WindowsInput::GetMousePosition_I()
   {
      GLFWwindow* x_Window = static_cast<GLFWwindow*>( Application::GetInstance().GetWindow().GetNativeWindow() );
      double xPos, yPos;
      glfwGetCursorPos( x_Window , &xPos, &yPos );
      return { (float)xPos, (float)yPos };
   }

   float WindowsInput::GetMouseX_I()
   {
      auto[x, y] = GetMousePosition_I();
      return x;
   }

   float WindowsInput::GetMouseY_I()
   {
      auto[x, y] = GetMousePosition_I();
      return y;
   }
}

