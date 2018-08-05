// SalamEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <thread>

#include "Renderer.h"
#include "GameLoop.h"


int main(int argc, char **argv)
{
	Renderer* renderer = new Renderer();
	GameLoop* gameLoop = new GameLoop();

	thread gameLoopThread(bind(&GameLoop::mainLoop, gameLoop));
	thread renderLoopThread(bind(&Renderer::renderLoop, renderer));

	GLFWwindow* window = NULL;

	while (gameLoop->isRunning())
	{
		if (window == NULL)
		{
			window = renderer->getWindow();
		}
		else 
		{
			gameLoop->handleInput(window);
		}
		
		this_thread::sleep_for(chrono::milliseconds(1));
	}
}

