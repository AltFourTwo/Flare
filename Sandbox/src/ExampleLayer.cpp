#include "SandboxPCH.h"
#include "ExampleLayer.h"

ExampleLayer::ExampleLayer() :
   Layer( "Test Layer" )
{}

void ExampleLayer::OnUpdate( Flare::Time::TimeStep a_TimeStep )
{
   //if ( Flare::UserInput::Input::IsKeyPressed( FLARE_KEY_G ) )
   //   Flare::Application::GetInstance().
}

void ExampleLayer::OnRender( Flare::Time::TimeStep a_TimeStep )
{

}

void ExampleLayer::OnEvent( Flare::Events::Event& a_Event )
{

}

void ExampleLayer::OnAttach()
{

}

void ExampleLayer::OnDetach()
{

}
