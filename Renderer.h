#pragma once

#include <glad/glad.h> 
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
		GLFWwindow* getWindow() { return window;  }

	private:
		void initialize();

		bool running;
		GLFWwindow* window;
};
