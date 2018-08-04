#pragma once

#include <iostream>
#include <chrono>
#include <thread>


using namespace std;

class GameLoop
{
	public:
		GameLoop();
		void mainLoop();
		bool isRunning() { return running; }

	private:
		bool running;
};