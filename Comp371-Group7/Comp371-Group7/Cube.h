#pragma once

#include "CommonLibrary.h"

using namespace std;

class Cube {
public:
	Cube(float u, float randomX, float setY, float randomZ, glm::vec3 color);
	Cube() {};
	~Cube();

	vector<GLfloat>* getVertices();
	vector<GLuint>* getIndices();
	vector <glm::vec3>* getNormals();

private:
	glm::vec3 vector1;
	glm::vec3 vector2;
	glm::vec3 vectorProduct;
	vector<GLfloat> localVertices;
	vector<GLuint> localIndices;
	vector<glm::vec3> localNormals;

	int randomColorOffset;
};