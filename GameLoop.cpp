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
		cout << "salame" << endl;
		this_thread::sleep_for(chrono::milliseconds(1));
	}

}