#pragma once
#include "Biome.h"
class Plains : public Biome
{
public:
	Plains();
	Plains(GLfloat pers, GLint octaves);
	~Plains();
};

