#pragma once

#include "Flare/UserInterface/Layer.h"

class ExampleLayer : public Flare::UserInterface::Layer
{
   public:
   ExampleLayer();

   public:
   virtual void OnUpdate( Flare::Time::TimeStep a_TimeStep ) override;
   virtual void OnRender( Flare::Time::TimeStep a_TimeStep ) override;
   virtual void OnEvent( Flare::Events::Event& a_Event ) override;
   virtual void OnAttach() override;
   virtual void OnDetach() override;
};