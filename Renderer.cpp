#include "stdafx.h"
#include "Renderer.h"

Renderer::Renderer()
{

}

void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Renderer::initialize()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(800, 600, "SalamEngine", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	glViewport(0, 0, 800, 600);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
}

void Renderer::renderLoop()
{
	running = true;
	initialize();
	
	using namespace std::chrono;
	milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	while (!glfwWindowShouldClose(window))
	{
		ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		float value = (ms.count() % 1000) / 1000.0f;
		glClearColor(value, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
		glfwSwapBuffers(window);

		this_thread::sleep_for(chrono::milliseconds(1));
	}

	glfwTerminate();
}

