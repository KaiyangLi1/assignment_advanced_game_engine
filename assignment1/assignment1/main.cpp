#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <sstream>
#include "triangle.h"
#include "Rectangle.h"
#include "polygon.h"
#include <cstdlib>


using namespace std;

void windowResizeCallBack(GLFWwindow* window, int width, int height);

void processInputs(GLFWwindow* window);

void showFPS(GLFWwindow* window);
int currentShape = 1;

void main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "My first openGL window: ", NULL, NULL);
	if (window == NULL)
	{
		cout << " Window failed!" << endl;
		
		glfwTerminate();
		system("pause");
		return;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "GLAD failed to initialise!" << endl;
		glfwTerminate();
		system("pause");
		return;
	}

	glViewport(0, 0, 800, 600);

	glfwSetWindowSizeCallback(window, windowResizeCallBack);


	rectangle rect;
	triangle rainbowTriangle;
	polygon poly;



	while (!glfwWindowShouldClose(window))
	{
		processInputs(window);
		glClearColor(0, 0.5, 0.5, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		if (currentShape == 1)
		{
			rainbowTriangle.draw();
		}
		else if(currentShape == 2)
		{
			rect.draw();
		}
		else if (currentShape == 3)
		{
			poly.draw();
		}

		glfwPollEvents();
		glfwSwapBuffers(window);

		showFPS(window);
	}

	glfwTerminate();
	system("pause");
}


void windowResizeCallBack(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInputs(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	else if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		currentShape = 1;
	}
	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
	{
		currentShape = 2;
	}
	else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
	{
		currentShape = 3;
	}
}

void showFPS(GLFWwindow* window)
{
	static double previousSeconds = 0.0;
	static int frameCount = 0;
	double elapsedSeconds;
	double currentSeconds = glfwGetTime();

	elapsedSeconds = currentSeconds - previousSeconds;
	if (elapsedSeconds > 0.25)
	{
		previousSeconds = currentSeconds;
		double fps = (double)frameCount / elapsedSeconds;
		double msPerFrame = 1000.0 / fps;

		stringstream ss;
		ss.precision(3);
		ss << std::fixed << "FPS: " << fps << " Frame time: " << msPerFrame << " (ms)" << endl;

		glfwSetWindowTitle(window, ss.str().c_str());

		frameCount = 0;
	}
	frameCount++;
}
