#pragma once

#include "CommonLibrary.h"

#include "VertexManager.h"
#include "Grid.h"
#include "Cloud.h"
#include "Bush.h"
#include "Pine.h"
#include "PineTree.h"
#include "Firefly.h"
#include "RotationalObject.h"
#include "Trunk.h"
#include "MapleTree.h"
#include "Cube.h"

using namespace std;

class WorldMesh {

	public:

		// Default Constructor
		WorldMesh();

		// Destructor
		~WorldMesh();

		// Getter: Return vertices
		vector<GLfloat>* getVertices() {
			return &vertices;
		};

		// Getter: Return Indices
		vector<GLuint>* getIndices() {
			return &indices;
		};

		// Getter: Return normals
		vector<glm::vec3>* getNormals() {
			return &normals;
		};

		VertexManager getVertexManager() { return vertexManager; }

	private:
		vector<GLfloat> vertices;
		vector<GLuint> indices;
		vector<glm::vec3> normals;
		VertexManager vertexManager;

};