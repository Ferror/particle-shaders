#include "pch.h"
#include "ParticleFragShader.h"


ParticleFragShader::ParticleFragShader()
{
}


ParticleFragShader::~ParticleFragShader()
{
}

std::string ParticleFragShader::Source()
{
	//***** TODO *****//
	return
		"#version 330 core\n"
		"in vec4 col;\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = col;\n"
		"}\0";
}

int ParticleFragShader::Type()
{
	return GL_FRAGMENT_SHADER;
}
