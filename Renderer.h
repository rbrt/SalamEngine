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
		void drawTriangle();

		bool running;
		GLFWwindow* window;

		unsigned int vertexShader;
		unsigned int fragmentShader;
		unsigned int shaderProgram;

		const char* vertexShaderSource = "#version 140\r\n"
			"#extension GL_ARB_explicit_attrib_location : require \n"
			"#extension GL_ARB_explicit_uniform_location : require \n"
			"in layout(location=0) vec3 aPos;"
			""
			"void main()"
			"{"
			"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);"
			"}";

		const char* fragmentShaderSource = "#version 330 core\n"
			"#extension GL_ARB_explicit_attrib_location : require \n"
			"#extension GL_ARB_explicit_uniform_location : require \n"
			"out vec4 fragColor;"
			""
			"void main()"
			"{"
			"	fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
			"}";
};
