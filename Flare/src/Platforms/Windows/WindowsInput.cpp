#include "FlarePCH.h"

#include "Flare/Application.h"
#include "WindowsInput.h"

#include <GLFW/glfw3.h>

namespace Flare::UserInterface
{
   bool WindowsInput::IsKeyPressed_I( int a_Keycode )
   {
      //auto& x_Window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
      //auto state = glfwGetKey( x_Window , a_Keycode );
      //return state == GFLW_PRESS || state == GLFW_REPEAT;

      return false;
   }

   bool WindowsInput::IsMouseButtonPressed_I( int a_Button )
   {
      //auto& x_Window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
      //auto state = glfwGetMouseButton( x_Window , a_Button );
      //return state == GFLW_PRESS;

      return false;
   }

   std::pair<float, float> WindowsInput::GetMousePosition_I() 
   {
      //auto& x_Window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
      double xPos, yPos;
      //auto state = glfwGetCursorPos( x_Window , &xPos, &yPos );
      //return state == GFLW_PRESS || state == GLFW_REPEAT;

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

