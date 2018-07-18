#include "Shader.h"
#include "enumHelper.h"
#include <exception>
#include <fstream>
#include <streambuf>

Shader::Shader(const std::string &shader, const ShaderType &type): shader(shader), type(type)
{
	shaderId = glCreateShader(getUnderlyingEnumValue(type));
}

Shader::~Shader() 
{
	glDeleteShader(shaderId);
}

std::unique_ptr<Shader> Shader::fromFile(const std::filesystem::path & filePath, const ShaderType & type)
{
	std::ifstream shaderFileStream(filePath);
	if (!shaderFileStream)
	{
		char error[kErrorMessageSize];
		strerror_s<kErrorMessageSize>(error, errno);
		std::string errorMessage(error);
		throw std::runtime_error(errorMessage);
	}

	std::string shaderString;

	shaderFileStream.seekg(0, std::ios::end);
	shaderString.reserve(shaderFileStream.tellg());
	shaderFileStream.seekg(0, std::ios::beg);

	shaderString.assign((std::istreambuf_iterator<char>(shaderFileStream)),
		std::istreambuf_iterator<char>());

	return std::make_unique<Shader>(shaderString, type);
}

void Shader::compile()
{
	const char* shaderCPtr = shader.c_str();
	glShaderSource(shaderId, 1, &shaderCPtr, NULL);
	glCompileShader(shaderId);

	int success;
	char infoLog[kErrorMessageSize];
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderId, kErrorMessageSize, NULL, infoLog);
		std::string errorMessage(infoLog);
		throw std::runtime_error(errorMessage);
	}
}
