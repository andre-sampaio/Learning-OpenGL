#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include "Program.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void preRender();
void render();

int main() {
	const int wWidth = 1024;
	const int wHeight = 768;

	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(wWidth, wHeight, "Learning-OpenGL", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		glfwTerminate();
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, wWidth, wHeight);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	preRender();
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.4f, 0.6f, 0.9f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

const std::array<float, 9> vertices = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f,  0.5f, 0.0f
};

std::unique_ptr<Program> program_ptr = nullptr;
std::unique_ptr<VertexArray> vao_ptr = nullptr;

void preRender()
{
	auto executionPath = std::filesystem::current_path();
	auto shadersPath = executionPath / "shaders";

	std::shared_ptr<Shader> vertexShader(std::move(Shader::fromFile(shadersPath / "vertex.glsl", ShaderType::Vertex)));
	vertexShader->compile();

	std::shared_ptr<Shader> fragmentShader(std::move(Shader::fromFile(shadersPath / "fragment.glsl", ShaderType::Fragment)));
	fragmentShader->compile();

	program_ptr = std::make_unique<Program>();

	program_ptr->attachShader(vertexShader);
	program_ptr->attachShader(fragmentShader);
	program_ptr->link();
	program_ptr->use();

	vao_ptr = std::make_unique<VertexArray>();
	vao_ptr->bind();

	std::shared_ptr<VertexBuffer> vbo_ptr = std::make_shared<VertexBuffer>();
	vao_ptr->store(vbo_ptr);

	vbo_ptr->bind();
	vbo_ptr->data(vertices);
	vbo_ptr->attributeData();
	vbo_ptr->enableAttributeData();
}

void render()
{
	program_ptr->use();
	vao_ptr->bind();
	vao_ptr->draw();
}