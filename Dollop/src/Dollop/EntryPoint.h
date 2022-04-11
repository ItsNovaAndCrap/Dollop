#pragma once

#ifdef DP_PLATFORM_WINDOWS

extern Dollop::Application* Dollop::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Dollop::CreateApplication();
	app->Run();
	delete app;
}

#endif