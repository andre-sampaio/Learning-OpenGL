#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &vaoId);
}


VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &vaoId);
}

void VertexArray::store(const vbo_ptr & vbo)
{
	vbos.push_back(vbo);
}

void VertexArray::bind() const
{
	glBindVertexArray(vaoId);
}

void VertexArray::draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
