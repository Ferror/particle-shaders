#include "pch.h"
#include "AGPUProgram.h"
#include <vector>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

bool AGPUProgram::programLinkStatus()
{
	{
		GLint status;
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);

		if (status == GL_FALSE) {
			GLint length;
			glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> log(length);
			glGetProgramInfoLog(shaderProgram, length, &length, &log[0]);
			std::cout << &log[0];
			return false;
		}

		std::cout << "Shaders linked to the program succesfully :-)";
		return true;
	}
}

AGPUProgram::AGPUProgram()
{
	
}

bool AGPUProgram::addShader(std::shared_ptr<AShader> shader)
{
	shader->initialize();
	if (!shader->Compile())
		return false;
	shaders.push_back(shader);
	return true;
}

bool AGPUProgram::linkShaders()
{
	shaderProgram = glCreateProgram();

	for (auto shader = shaders.begin(); shader != shaders.end(); ++shader) {
		glAttachShader(shaderProgram, (*shader)->ShaderGLObj());
	}

	glLinkProgram(shaderProgram);

	return programLinkStatus();
	
}

void AGPUProgram::addMatrix4x4f(glm::mat4 matrix, const GLchar* varName)
{
	GLuint loc = glGetUniformLocation(shaderProgram,varName);
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(matrix));
}

void AGPUProgram::addFloat(GLfloat f, const GLchar * varName)
{
	GLuint loc = glGetUniformLocation(shaderProgram, varName);
	glUniform1f(loc, f);
}

AGPUProgram::~AGPUProgram()
{
}
