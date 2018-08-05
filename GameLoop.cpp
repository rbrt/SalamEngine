#include "stdafx.h"
#include "GameLoop.h"

GameLoop::GameLoop()
{
	
}


void GameLoop::mainLoop()
{
	running = true;
	while (running)
	{
		this_thread::sleep_for(chrono::milliseconds(1));
	}

}

void GameLoop::handleInput(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		cout << "escape" << endl;
	}
}
