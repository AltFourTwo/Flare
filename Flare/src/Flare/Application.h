#pragma once

#include "Core.h"

namespace Flare {

	class FLARE_API Application
	{
	
	public:
	
		Application();
		virtual ~Application();
      void Run();
      void Test();


	};

   // To be defined in client
   Application* Initialize();

}
