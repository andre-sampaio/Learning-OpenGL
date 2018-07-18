#include "Program.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Program::Program()
{
	programId = glCreateProgram();
}

Program::~Program()
{
}

void Program::attachShader(Shader_ptr &shader)
{
	shaders.push_back(shader);
}

void Program::link()
{
	for (auto shader : shaders) 
	{
		glAttachShader(programId, shader->getShaderId());
	}

	glLinkProgram(programId);

	int success;
	char infoLog[kErrorMessageSize];

	glGetProgramiv(programId, GL_LINK_STATUS, &success);
	if (!success) 
	{
		glGetProgramInfoLog(programId, kErrorMessageSize, NULL, infoLog);
		std::string errorMessage(infoLog);
		throw std::runtime_error(errorMessage);
	}
}

void Program::use() const
{
	glUseProgram(programId);
}
