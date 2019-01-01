#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
class polygon
{
public:
	unsigned int vbo;
	unsigned int vao;
	unsigned int ebo;
	
	Shader* shader;

	polygon();
	~polygon();

	void draw();
};

