#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "shader.h"

class triangle
{
public:
	unsigned int vbo;
	unsigned int vao;
	Shader* shader;

	triangle();
	~triangle();

	void draw();
};

