#include <Dollop.h>

class Sandbox : public Dollop::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Dollop::Application* Dollop::CreateApplication()
{
	return new Sandbox();
}