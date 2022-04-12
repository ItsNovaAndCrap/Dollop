#pragma once

#ifdef DP_PLATFORM_WINDOWS

extern Dollop::Application* Dollop::CreateApplication();

int main(int argc, char** argv)
{
	Dollop::Log::Init();
	DP_CORE_WARN("Initialized Log!");
	int a = 5;
	DP_INFO("Hello! Var={0}", a);

	auto app = Dollop::CreateApplication();
	app->Run();
	delete app;
}

#endif