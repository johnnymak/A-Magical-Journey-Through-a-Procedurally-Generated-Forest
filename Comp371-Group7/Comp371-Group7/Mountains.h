#pragma once
#include "Biome.h"
class Mountains : public Biome
{
public:
	Mountains();
	Mountains(GLfloat pers, GLint octaves);
	~Mountains();
};

