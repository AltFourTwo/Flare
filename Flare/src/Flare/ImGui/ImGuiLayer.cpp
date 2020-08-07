#include "FlarePCH.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Platforms/OpenGL/ImGuiOpenGLRenderer.h"

#include "Flare/Application.h"
#include "Platforms/Windows/WindowsWindow.h"

// TMEPORARY
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Flare::ProtoImGui
{
   ImGuiLayer::ImGuiLayer() :
      Layer( "ImGui Layer" )
   {}

   ImGuiLayer::~ImGuiLayer() {}

   void ImGuiLayer::OnAttach()
   {
      ImGui::CreateContext();
      ImGui::StyleColorsDark();

      ImGuiIO& x_IO = ImGui::GetIO();
      x_IO.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
      x_IO.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

      // Temporary
      x_IO.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
      x_IO.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
      x_IO.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
      x_IO.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
      x_IO.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
      x_IO.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
      x_IO.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
      x_IO.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
      x_IO.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
      x_IO.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
      x_IO.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
      x_IO.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
      x_IO.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
      x_IO.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
      x_IO.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
      x_IO.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
      x_IO.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
      x_IO.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
      x_IO.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
      x_IO.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
      x_IO.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
      x_IO.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

      ImGui_ImplOpenGL3_Init( "#version 430 core" );
   }

   void ImGuiLayer::OnDetach()
   {

   }

   void ImGuiLayer::OnEvent( Events::Event& a_Event )
   {
      Flare::Events::EventDispatcher x_Dispatcher( a_Event );
      x_Dispatcher.Dispatch<Flare::Events::MouseButtonPressedEvent>( FLARE_BIND_EVENT_FN( ImGuiLayer::OnMouseButtonPressed ) );
      x_Dispatcher.Dispatch<Flare::Events::MouseButtonReleasedEvent>( FLARE_BIND_EVENT_FN( ImGuiLayer::OnMouseButtonReleased ) );
      x_Dispatcher.Dispatch<Flare::Events::MouseMovedEvent>( FLARE_BIND_EVENT_FN( ImGuiLayer::OnMouseMoved ) );
      x_Dispatcher.Dispatch<Flare::Events::MouseScrolledEvent>( FLARE_BIND_EVENT_FN( ImGuiLayer::OnMouseScrolled ) );
      x_Dispatcher.Dispatch<Flare::Events::KeyPressedEvent>( FLARE_BIND_EVENT_FN( ImGuiLayer::OnKeyPressed ) );
      x_Dispatcher.Dispatch<Flare::Events::KeyReleasedEvent>( FLARE_BIND_EVENT_FN( ImGuiLayer::OnKeyReleased ) );
      x_Dispatcher.Dispatch<Flare::Events::KeyTypedEvent>( FLARE_BIND_EVENT_FN( ImGuiLayer::OnKeyTyped ) );
      x_Dispatcher.Dispatch<Flare::Events::WindowResizeEvent>( FLARE_BIND_EVENT_FN( ImGuiLayer::OnWindowResized ) );
   }

   void ImGuiLayer::OnUpdate( Time::TimeStep a_TimeStep )
   {

   }

   void ImGuiLayer::OnRender( Time::TimeStep a_TimeStep )
   {
      ImGuiIO& x_IO = ImGui::GetIO();
      Application& x_App = Application::GetInstance();
      x_IO.DisplaySize = ImVec2( x_App.GetWindow().GetWidth(), x_App.GetWindow().GetHeight() );
      x_IO.DeltaTime = a_TimeStep;
      static bool s_Show = true;

      ImGui_ImplOpenGL3_NewFrame();
      ImGui::NewFrame();
      ImGui::ShowDemoWindow( &s_Show );
      ImGui::Render();
      ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );
   }

   bool ImGuiLayer::OnMouseButtonPressed( Flare::Events::MouseButtonPressedEvent& a_Event )
   {
      ImGuiIO& x_IO = ImGui::GetIO();
      x_IO.MouseDown[a_Event.GetMouseButton()] = true;

      return false;
   }

   bool ImGuiLayer::OnMouseButtonReleased( Flare::Events::MouseButtonReleasedEvent& a_Event )
   {
      ImGuiIO& x_IO = ImGui::GetIO();
      x_IO.MouseDown[a_Event.GetMouseButton()] = false;
      return false;
   }

   bool ImGuiLayer::OnMouseMoved( Flare::Events::MouseMovedEvent& a_Event )
   {
      ImGuiIO& x_IO = ImGui::GetIO();
      x_IO.MousePos = ImVec2( a_Event.GetX(), a_Event.GetY() );

      return false;
   }

   bool ImGuiLayer::OnMouseScrolled( Flare::Events::MouseScrolledEvent& a_Event )
   {
      ImGuiIO& x_IO = ImGui::GetIO();
      x_IO.MouseWheelH = a_Event.GetXOffSet();
      x_IO.MouseWheel = a_Event.GetYOffSet();
      return false;
   }

   bool ImGuiLayer::OnKeyPressed( Flare::Events::KeyPressedEvent& a_Event )
   {
      ImGuiIO& x_IO = ImGui::GetIO();
      x_IO.KeysDown[a_Event.GetKeyCode()] = true;
      x_IO.KeyAlt = x_IO.KeysDown[GLFW_KEY_LEFT_ALT] || x_IO.KeysDown[GLFW_KEY_RIGHT_ALT];
      x_IO.KeyCtrl = x_IO.KeysDown[GLFW_KEY_LEFT_CONTROL] || x_IO.KeysDown[GLFW_KEY_RIGHT_CONTROL];
      x_IO.KeyShift = x_IO.KeysDown[GLFW_KEY_LEFT_SHIFT] || x_IO.KeysDown[GLFW_KEY_RIGHT_SHIFT];
      x_IO.KeySuper = x_IO.KeysDown[GLFW_KEY_LEFT_SUPER] || x_IO.KeysDown[GLFW_KEY_RIGHT_SUPER];

      return false;
   }

   bool ImGuiLayer::OnKeyReleased( Flare::Events::KeyReleasedEvent& a_Event )
   {
      ImGuiIO& x_IO = ImGui::GetIO();
      x_IO.KeysDown[a_Event.GetKeyCode()] = false;
      return false;
   }

   bool ImGuiLayer::OnKeyTyped( Flare::Events::KeyTypedEvent& a_Event )
   {
      ImGuiIO& x_IO = ImGui::GetIO();
      int x_KeyCode = a_Event.GetKeyCode();
      if ( x_KeyCode > 0 && x_KeyCode < 0x10000 )
         x_IO.AddInputCharacter( (unsigned short)x_KeyCode );

      return false;
   }

   bool ImGuiLayer::OnWindowResized( Flare::Events::WindowResizeEvent& a_Event )
   {
      ImGuiIO& x_IO = ImGui::GetIO();
      x_IO.DisplaySize = ImVec2( a_Event.GetWidth(), a_Event.GetHeight() );
      x_IO.DisplayFramebufferScale = ImVec2( 1.0f, 1.0f );
      glViewport( 0, 0, a_Event.GetWidth(), a_Event.GetHeight() );

      return false;
   }

   bool ImGuiLayer::OnClipBoardCut( Flare::Events::ClipBoardCutEvent& a_Event )
   {
      ImGuiIO& x_IO = ImGui::GetIO();

      return false;
   }

   bool ImGuiLayer::OnClipBoardCopy( Flare::Events::ClipBoardCopyEvent& a_Event )
   {
      ImGuiIO& x_IO = ImGui::GetIO();

      return false;
   }

   bool ImGuiLayer::OnClipBoardPaste( Flare::Events::ClipBoardPasteEvent& a_Event )
   {
      ImGuiIO& x_IO = ImGui::GetIO();

      //Flare::UserInterface::Window& x_Window = Application::GetInstance().GetWindow();
      //const char* x_Data = glfwGetClipboardString( (GLFWwindow*)x_Window.GetNativeWindow()) ;
      //x_IO.SetClipboardTextFn(x_Data)

      return false;
   }
}