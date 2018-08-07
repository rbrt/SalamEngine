// SalamEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vulkan/vulkan.h>
#include <iostream>
#include <chrono>
#include <thread>

#include "Renderer.h"
#include "GameLoop.h"


int main(int argc, char **argv)
{
    const char* versionString = "0.0.0";

    Renderer* renderer = new Renderer();
    GameLoop* gameLoop = new GameLoop();
    thread renderLoopThread(bind(&Renderer::run, renderer));

    GLFWwindow* window = NULL;

    cout << "SalamEngine " << versionString << endl;

    while (gameLoop->isRunning())
    {
        if (window == NULL)
        {
            //window = renderer->getWindow();
        }
        else 
        {
            gameLoop->handleInput(window);
            gameLoop->mainLoop();
        }
        
        this_thread::sleep_for(chrono::milliseconds(1));
    }
}

