#include "triangle.h"



triangle::triangle()
{
	shader = new Shader("triangleVertexShader.txt", "triangleFragmentShader.txt");
	float triangleVertices[]=
	{
		0.5f, -0.5f, 0,    1, 0, 0,
		-0.5f, -0.5f, 0,   0, 1, 0,
		0.0f, 0.5f,  0,    0, 0, 1,
	};

	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindVertexArray(vao);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
}


triangle::~triangle()
{
	delete shader;
}

void triangle::draw()
{
	shader->use();
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}