#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
#include "VertexBuffer.h"

class VertexArray
{
	using vbo_ptr = std::shared_ptr<VertexBuffer>;
public:
	VertexArray();
	~VertexArray();

	void store(const vbo_ptr &vbo);

	void bind() const;

	static void draw();
private:
	unsigned int vaoId = 0;
	std::vector<vbo_ptr> vbos;
};