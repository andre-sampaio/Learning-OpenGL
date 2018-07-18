#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <filesystem>
#include <memory>
#include <string>

enum class ShaderType {
	Vertex = GL_VERTEX_SHADER,
	Fragment = GL_FRAGMENT_SHADER
};

class Shader
{
public:
	static std::unique_ptr<Shader> fromFile(const std::filesystem::path &filePath, const ShaderType &type);

	Shader(const std::string &shader, const ShaderType &type);
	~Shader();
	
	void compile();
	inline unsigned int getShaderId() const { return shaderId; }
private:
	const std::string shader;
	const ShaderType type;
	unsigned int shaderId = 0;
	static constexpr int kErrorMessageSize = 512;
};

