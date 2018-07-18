#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &vboId);
}


VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &vboId);
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
}

void VertexBuffer::attributeData()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

void VertexBuffer::enableAttributeData()
{
	glEnableVertexAttribArray(0);
}
