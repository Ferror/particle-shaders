#include "pch.h"

#include <GL/glew.h>
#include <GL/glut.h>
#include "SphereScene.h"
#include "ParticleScene.h"
#include "ParticleEffect.h"

//SphereScene<SphereGPUProgram, VertexGenerator> scene;
ParticleScene<OnePointParticleEffect, OnePointParticleEffect> scene;

void display() {
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	scene.frame();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_MULTISAMPLE);
	
	glutCreateWindow("GK: Fragment and vertex shaders");
	glutReshapeWindow(1000, 600);
	glutDisplayFunc(display);
	scene.init();
	glutMainLoop();

	return 0;
}
