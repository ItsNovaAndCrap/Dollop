#pragma once

#include "Core.h"

namespace Dollop {

	class DOLLOP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in the application.
	Application* CreateApplication();

}