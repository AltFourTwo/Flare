#include "FlarePCH.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Platforms/OpenGL/ImGuiOpenGLRenderer.h"
#include "GLFW/glfw3.h"

#include "Flare/Application.h"

namespace Flare::ProtoImGui
{
   ImGuiLayer::ImGuiLayer() :
      Layer("ImGui Layer")
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

      ImGui_ImplOpenGL3_Init("#version 430 core");
   }

   void ImGuiLayer::OnDetach()
   {
   
   }

   void ImGuiLayer::OnEvent( Events::Event & a_Event )
   {
   
   }

   void ImGuiLayer::OnUpdate( Time::TimeStep a_TimeStep )
   {
   
   }

   void ImGuiLayer::OnRender( Time::TimeStep a_TimeStep )
   {
      ImGuiIO& x_IO = ImGui::GetIO();
      Application& x_App = Application::GetInstance();
      x_IO.DisplaySize = ImVec2(x_App.GetWindow().GetWidth(), x_App.GetWindow().GetHeight());
      x_IO.DeltaTime = a_TimeStep;
      static bool s_Show = true;

      ImGui_ImplOpenGL3_NewFrame();
      ImGui::NewFrame();
      ImGui::ShowDemoWindow(&s_Show);
      ImGui::Render();
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
   }
}