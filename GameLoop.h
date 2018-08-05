#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <glfw3.h>

using namespace std;

class GameLoop
{
	public:
		GameLoop();
		void mainLoop();
		bool isRunning() { return running; }
		void handleInput(GLFWwindow* window);

	private:
		

		bool running;
};