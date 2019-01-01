#include "Rectangle.h"



rectangle::rectangle()
{
	shader = new Shader("rectangleVertexShader.txt", "rectangleFragmentShader.txt");
	float rectangleVertices[]=
	{
		0.5f, 0.5f, 0, 
		0.5f, -0.5f, 0,
		-0.5, -0.5f, 0,
		-0.5f, 0.5f, 0 
	};
	unsigned int indices[] =
	{
		0, 1, 3,
		1, 2, 3 
	};
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rectangleVertices), rectangleVertices, GL_STATIC_DRAW);
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}

rectangle::~rectangle()
{
	delete shader;
}
void rectangle::draw()
{
	shader->use();
	float greenValue = sin(glfwGetTime()) / 2.0f + 0.5f;
	int ourColourUniformLocation = glGetUniformLocation(shader->ID, "ourColour");
	glUniform4f(ourColourUniformLocation, greenValue, greenValue, greenValue, 1.0f);
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
