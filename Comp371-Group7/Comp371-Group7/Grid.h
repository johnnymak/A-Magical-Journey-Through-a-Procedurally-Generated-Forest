#pragma once

#include "CommonLibrary.h"

using namespace std;

class Grid {

	public: 
		Grid();

		Grid(GLfloat length, int halfGridSize, glm::vec3 color);

		~Grid();

		vector<GLfloat>* getVertices();
		vector<GLuint>* getIndices();
		vector<glm::vec3>* getNormals();

		int getGridSize();
		glm::vec3 getVertex(int coordX, int coordY);

		void setVertexY(int coordX, int coordY, GLfloat newValue);
		void setVertexOpacity(int coordX, int coordY, GLfloat opacity);

		void addDirtPatch(int coordX, int coordY);
		float distance(int x1, int y1, int x2, int y2);
		float valueClamp(float value);

		void Grid::printGrid();
		

	private:
		glm::vec3 vector1;
		glm::vec3 vector2;
		glm::vec3 vectorProduct;
		vector<GLfloat> localVertices;
		vector<GLuint> localIndices;
		vector<glm::vec3> localNormals;
		int gridSize;
		int randomColorOffset;

};