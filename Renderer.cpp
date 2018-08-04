#include "stdafx.h"
#include "Renderer.h"

Renderer::Renderer()
{

}

void Renderer::renderLoop()
{
	running = true;
	while (running)
	{
		cout << "render" << endl;
		this_thread::sleep_for(chrono::milliseconds(1));
	}
}