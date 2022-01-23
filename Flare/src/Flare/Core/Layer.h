#pragma once

#include "Flare/Core/Core.h"
#include "Flare/Core/TimeStep.h"
#include "Flare/Events/Event.h"

namespace Flare::UserInterface
{
   class Layer
   {
      /*****   VARIABLES   *****/
      protected:
      std::string m_DebugName;

      /*****  C-TOR D-TOR  *****/
      public:
      Layer( const std::string& a_Name = "Layer" );
      virtual ~Layer();

      /*****   FUNCTIONS   *****/
      public:
      virtual void OnAttach() {}
      virtual void OnDetach() {}
      virtual void OnEvent( Flare::Events::Event& a_Event ) {}
      virtual void OnUpdate( Time::TimeStep a_TimeStep ) {}
      virtual void OnRender( Time::TimeStep a_TimeStep ) {}
      virtual void OnImGuiRender() {}

      /*****   GETTERS   *****/
      public:
      inline const std::string& GetDebugName() const { return m_DebugName; }
   };
}