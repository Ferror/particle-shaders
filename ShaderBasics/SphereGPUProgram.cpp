#pragma once
#include "pch.h"
#include "SphereGPUProgram.h"

SphereGPUProgram::SphereGPUProgram()
{
}

SphereGPUProgram::~SphereGPUProgram()
{
}

bool SphereGPUProgram::bindVertieces(VertexGenerator& vGen, float dT, float wT)
{
	//***** TODO *****//
	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	//Bind vertex object
	glBindVertexArray(VAO);

	float p[6] = { -3.14f, 3.14f, 0.0314f, -3.14f, 3.14f, 0.0314f };
	float* verticles = vGen.generateVertieces(p);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vGen.Size() * vGen.Count() * vGen.Dim() * sizeof(float), verticles, GL_STATIC_DRAW);

	//Kopiuje atrybuty xyz do shadera
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);

	//atrybuty rgb
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*) (3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glUseProgram(shaderProgram);

	//kasujemy bo dane do OpenGL juz poszly
	delete[] verticles;

	return true;
}
