#include "polygon.h"



polygon::polygon()
{
	shader = new Shader("polygonVertexShader.txt", "polygonFragmentShader.txt");
	float polygonVertices[] =
	{
		-1.0f, -0.5f, 0.0f,
		-0.7f, 0.2f, 0.0f,
		0.0f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
		0.7f, 0.2f, 0.0f,
		1.0f, -0.5f, 0.0f
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		1, 2, 3,
		2, 4, 5
	};

	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(polygonVertices), polygonVertices, GL_STATIC_DRAW);
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

}


polygon::~polygon()
{
	delete shader;
}

void polygon::draw()
{
	shader->use();
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
}