#pragma once

#include <array>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class VertexBuffer
{
public:
	VertexBuffer();
	~VertexBuffer();

	void bind() const;

	template<unsigned int SIZE> static void data(const std::array<float, SIZE> &arr);
	static void attributeData();
	static void enableAttributeData();
private:
	unsigned int vboId = 0;
};

template<unsigned int SIZE>
inline void VertexBuffer::data(const std::array<float, SIZE> &arr)
{
	glBufferData(GL_ARRAY_BUFFER, sizeof(arr), arr.data(), GL_STATIC_DRAW);
}
