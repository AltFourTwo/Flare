#include "SandboxPCH.h"

#include "Flare/UserInterface/Layer.h"

class ExampleLayer : public Flare::UserInterface::Layer
{
   public:
   ExampleLayer() :
      Layer( "Test Layer" )
   {}

   virtual void Layer::OnUpdate( Flare::Time::TimeStep a_TimeStep ) 
   {
      
   }

   virtual void Layer::OnRender( Flare::Time::TimeStep a_TimeStep )
   {

   }

   virtual void Layer::OnEvent( Flare::Events::Event& a_Event )
   {

   }

   virtual void Layer::OnAttach()
   {

   }

   virtual void Layer::OnDetach()
   {

   }
};