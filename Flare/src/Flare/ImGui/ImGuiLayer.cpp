#include "FlarePCH.h"
#include "ImGuiLayer.h"

#include "Flare/Core/Application.h"
#include "Platforms/Windows/WindowsWindow.h"

#include <imgui.h>

// TEMPORARY ?
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <examples\imgui_impl_opengl3.h>
#include <examples\imgui_impl_glfw.h>

namespace Flare::ProtoImGui
{
   ImGuiLayer::ImGuiLayer() :
      Layer( "ImGui Layer" )
   {}

   ImGuiLayer::~ImGuiLayer() {}

   void ImGuiLayer::OnAttach()
   {
      // Setup Dear ImGui Context
      IMGUI_CHECKVERSION();
      ImGui::CreateContext();
      ImGuiIO& x_IO = ImGui::GetIO();

      x_IO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
      //x_IO.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
      x_IO.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
      x_IO.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

      ImGui::StyleColorsDark();

      // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
      ImGuiStyle& x_Style = ImGui::GetStyle();
      if ( x_IO.ConfigFlags & ImGuiConfigFlags_ViewportsEnable )
      {
         x_Style.WindowRounding = 0.0f;
         x_Style.Colors[ImGuiCol_WindowBg].w = 1.0f;
      }

      Application& x_App = Application::GetInstance();
      GLFWwindow* x_Window = static_cast<GLFWwindow*>( x_App.GetWindow().GetNativeWindow() );

      // Setup Platform/Renderer bindings.
      ImGui_ImplGlfw_InitForOpenGL( x_Window, true );
      ImGui_ImplOpenGL3_Init( "#version 430 core" );
   }

   void ImGuiLayer::OnDetach()
   {
      ImGui_ImplOpenGL3_Shutdown();
      ImGui_ImplGlfw_Shutdown();
      ImGui::DestroyContext();
   }

   void ImGuiLayer::OnImGuiRender()
   {
      static bool s_Show = true;
      ImGui::ShowDemoWindow( &s_Show );
   }

   void ImGuiLayer::Begin()
   {
      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplGlfw_NewFrame();
      ImGui::NewFrame();
   }

   void ImGuiLayer::End()
   {
      ImGuiIO x_IO = ImGui::GetIO();
      Application& x_App = Application::GetInstance();
      x_IO.DisplaySize = ImVec2( (float)x_App.GetWindow().GetWidth(), (float)x_App.GetWindow().GetHeight() );

      // Rendering
      ImGui::Render();
      ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );

      if ( x_IO.ConfigFlags & ImGuiConfigFlags_ViewportsEnable )
      {
         GLFWwindow* x_BackupCurrentContext = static_cast<GLFWwindow*>( x_App.GetWindow().GetNativeWindow() );
         ImGui::UpdatePlatformWindows();
         ImGui::RenderPlatformWindowsDefault();
         glfwMakeContextCurrent( x_BackupCurrentContext );
      }
   }
}