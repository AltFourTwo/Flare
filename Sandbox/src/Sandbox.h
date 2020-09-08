#pragma once

#include <Flare.h>

class Sandbox : public Flare::Application, public Flare::Logging::LogEmitter
{
   public:
   Sandbox();
   ~Sandbox();
};