#pragma once

#include "CommonLibrary.h"

using namespace std;

class Trunk {
	public:
		Trunk() {};
		Trunk(float u, glm::vec3 center, glm::vec3 color);
		~Trunk();

		float highestVertex() {
			float max = 0.0;
			for (int i = 1; i < localVertices.size() - 1; i += 3) {
				if (max < localVertices.at(i))
					max = localVertices.at(i);
			}
			return max;
		}

		vector<GLfloat>* getVertices();
		vector<GLuint>* getIndices();
		vector<glm::vec3>* getNormals();

private:
	glm::vec3 vector1;
	glm::vec3 vector2;
	glm::vec3 vectorProduct;
	vector<GLfloat> localVertices;
	vector<GLuint> localIndices;
	vector<glm::vec3> localNormals;

	int profileCurveLength;
	int trajectoryCurveLength;

	int randomColorOffset;
	glm::vec3 center = glm::vec3(0.2f, 0.2f, 0.2f);

	GLfloat pushValueLimit(GLuint value);
};
