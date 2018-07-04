#pragma once
#include "CommonLibrary.h"


class Biome
{
public:
	Biome();
	Biome(GLfloat persistance, GLint octaves);
	~Biome();

	GLfloat getPersistance();
	GLint getOctaves();

private:
	GLfloat persistance;
	GLint octaves;
};

