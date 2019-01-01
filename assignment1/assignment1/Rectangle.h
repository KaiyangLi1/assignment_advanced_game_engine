#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "shader.h"

class rectangle
{
public:
	unsigned int vbo;
	unsigned int vao;
	unsigned int ebo;

	Shader* shader;

	rectangle();
	~rectangle();

	void draw();
};

