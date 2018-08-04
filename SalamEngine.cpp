// SalamEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <chrono>
#include <thread>

#include "GameLoop.h"
#include "Renderer.h"

int main(int argc, char **argv)
{
	GameLoop* gameLoop = new GameLoop();
	Renderer* renderer = new Renderer();
	
	thread gameLoopThread(bind(&GameLoop::mainLoop, gameLoop));
	thread renderLoopThread(bind(&Renderer::renderLoop, renderer));

	while (gameLoop->isRunning())
	{
		std::cout << "main" << std::endl;
		this_thread::sleep_for(chrono::milliseconds(1));
	}
}

