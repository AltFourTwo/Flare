#pragma once

#include "Core.h"

namespace SquareFlare {

	class SQFL_API Application
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
