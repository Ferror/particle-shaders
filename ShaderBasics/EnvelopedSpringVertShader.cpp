#include "pch.h"
#include "EnvelopedSpringVertShader.h"

EnvelopedSpringVertShader::EnvelopedSpringVertShader()
{
}

EnvelopedSpringVertShader::~EnvelopedSpringVertShader()
{
}

std::string EnvelopedSpringVertShader::Source()
{
	//***** TODO *****//
	return
		"#version 330 core\n"
		"layout (location=0) in float time;\n"
		"layout (location=1) in vec3 p;\n"
		"layout (location=2) in vec4 c;\n"
		"layout (location=3) in vec2 phase;\n"
		"uniform float amplitudeCos;\n"
		"uniform float amplitudeSin;\n"
		"uniform float expFrequencyCos;\n"
		"uniform float expFrequencySin;\n"
		"uniform float cosFrequency;\n"
		"uniform float sinFrequency;\n"
		"uniform float cosPhase;\n"
		"uniform float sinPhase;\n"
		"out vec4 col;\n"
		"uniform mat4 proj;\n"
		"uniform mat4 view;\n"
		"float rand(vec2 co) {\n"
		"	return fract(sin(dot(co.xy, vec2(12.9898, 78.233))) * 43758.5453);\n"
		"}\n"
		"void main()\n"
		"{\n"
		"	float x,z,t,r,s;\n"
		"	r=rand(vec2(time, p.y));\n"
		"	t=(1-r*0.4)*(6.5-time*5);\n"
		"	s=1-0.0*rand(vec2(time, p.z));\n"
		"	x=amplitudeCos*exp(-t*t*expFrequencyCos)*cos(cosFrequency*t+phase.x*s);\n"
		"	z=amplitudeSin*exp(-t*t*expFrequencySin)*sin(sinFrequency*t+phase.y*s);\n"
		"	gl_Position = (proj*view)*vec4(p.x+x, p.y-time, p.z+z, 1.0);\n"
		"	col=vec4(1,1,1,1);\n"
		"}\0";
}

/*
std::string EnvelopedSpringVertShader::Source()
{
	return
		"#version 330 core\n"
		"float rand(vec2 co) {\n"
		"	return fract(sin(dot(co.xy, vec2(12.9898, 78.233))) * 43758.5453);\n"
		"}\n"
		"void main()\n"
		"{\n"
		"}\0";
}
*/
