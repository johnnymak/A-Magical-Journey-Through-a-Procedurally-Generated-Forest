#include "Biome.h"

Biome::Biome()
{
}

Biome::Biome(GLfloat persistance, GLint octaves)
{
	this->persistance = persistance;
	this->octaves = octaves;
}


Biome::~Biome()
{
}

GLfloat Biome::getPersistance()
{
	return this->persistance;
}

GLint Biome::getOctaves()
{
	return this->octaves;
}
