#pragma once

#include "CommonLibrary.h"
#include "Shaders/Shader.h"

using namespace std;

class Firefly {
public:
	Firefly(int num) {
		numberOfFireflies = num;
		generatePositions();
	};

	~Firefly() { };

	void generatePositions() {
		for (int i = 0; i < numberOfFireflies; i++) {
			x = static_cast <float> (rand() % GRID_SIZE*4 - GRID_SIZE * 2) + 0.01;
			y = static_cast <float> (rand() % 20 + 10) + 0.01;
			z = static_cast <float> (rand() % GRID_SIZE*4 - GRID_SIZE * 2) + 0.01;
			glm::vec3 pos = glm::vec3(x, y, z);
			pointLightPositions.push_back(pos);
		}

	}

	vector<glm::vec3> getPositions() {
		return pointLightPositions
			;
	}

	void draw(Shader ourShader) {

		for (int i = 0; i < pointLightPositions.size(); i++) {

			char varr[50];
			string s = std::to_string(i);
			char const *pchar = s.c_str();

			strcpy(varr, "pointLights[");
			strcat(varr, pchar);
			strcat(varr, "].position");


			glUniform3f(glGetUniformLocation(ourShader.Program, varr), pointLightPositions[i].x, pointLightPositions[i].y, pointLightPositions[i].z);

			strcpy(varr, "pointLights[");
			strcat(varr, pchar);
			strcat(varr, "].ambient");

			glUniform3f(glGetUniformLocation(ourShader.Program, varr), 0.7921f, 0.9922f, 1.0f);

			strcpy(varr, "pointLights[");
			strcat(varr, pchar);
			strcat(varr, "].diffuse");


			glUniform3f(glGetUniformLocation(ourShader.Program, varr), 0.7921f, 0.9922f, 1.0f);

			strcpy(varr, "pointLights[");
			strcat(varr, pchar);
			strcat(varr, "].specular");

			glUniform3f(glGetUniformLocation(ourShader.Program, varr), 0.7921f, 0.9922f, 1.0f);

			strcpy(varr, "pointLights[");
			strcat(varr, pchar);
			strcat(varr, "].constant");

			glUniform1f(glGetUniformLocation(ourShader.Program, varr), 1.0f);

			strcpy(varr, "pointLights[");
			strcat(varr, pchar);
			strcat(varr, "].linear");

			glUniform1f(glGetUniformLocation(ourShader.Program, varr), 0.0005);

			strcpy(varr, "pointLights[");
			strcat(varr, pchar);
			strcat(varr, "].quadratic");

			glUniform1f(glGetUniformLocation(ourShader.Program, varr), 0.008);
		}
	}

	int getNumber() {
		return numberOfFireflies;
	}
	
private:
	vector<glm::vec3> pointLightPositions;
	int numberOfFireflies;
	float x, y, z;
};