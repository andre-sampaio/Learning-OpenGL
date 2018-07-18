#pragma once
#include "Shader.h"
#include <memory>
#include <vector>

class Program
{
	using Shader_ptr = std::shared_ptr<Shader>;

public:
	Program();
	~Program();
	void attachShader(Shader_ptr &shader);
	void link();
	void use() const;
private:
	unsigned int programId = 0;
	std::vector<Shader_ptr> shaders;
	static constexpr int kErrorMessageSize = 512;
};

