#include "stdafx.h"
#include "GameLoop.h"

GameLoop::GameLoop()
{
	
}


void GameLoop::mainLoop()
{

}

void GameLoop::handleInput(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		cout << "escape" << endl;
	}
}
