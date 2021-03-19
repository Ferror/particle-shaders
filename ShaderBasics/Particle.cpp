#include "pch.h"
#include "Particle.h"


void Particle::operator()(float* vertieces, int& index, float dT, bool updateAge)
{
	//***** TODO *****//
	if (updateAge) {
		age += dT;
	}

	vertieces[index] = age;
	vertieces[++index] = sPosX;
	vertieces[++index] = sPosY;
	vertieces[++index] = sPosZ;

	vertieces[++index] = 1.0f;
	vertieces[++index] = 1.0f;
	vertieces[++index] = 1.0f;
	vertieces[++index] = 1.0f;

	vertieces[++index] = phaseX;
	vertieces[++index] = phaseY;

	index += 1;
}

Particle::~Particle()
{
}
