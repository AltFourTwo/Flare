#pragma once

#include "Core.h"

namespace Flare2D {


	class F2D_API Application
	{
	
	public:
	
		Application();
		virtual ~Application();
      void Run();
	};

   // To be defined in client
   Application* Initialize();

}
