#pragma once

#include <glfw3.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Renderer
{
	public:
		Renderer();
		void renderLoop();

	private:
		
		bool running;
};
