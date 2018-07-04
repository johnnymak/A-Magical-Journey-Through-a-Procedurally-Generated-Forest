#pragma once

#include "CommonLibrary.h"

using namespace std;

class VertexManager {

	public: 
		// Constructor
		VertexManager();
		VertexManager(vector<GLfloat>* vertices, vector<GLuint>* indices, vector<glm::vec3>* normals);

		// Destructor
		~VertexManager();

		// Class Functions: Helper to Update Vertices, Indices, and Normals (Takes care of call order)
		void VertexManager::updateMeshes(vector<GLfloat>* inputVertices, vector<GLuint>* inputIndices, vector<glm::vec3>* inputNormals);

	private: 
		vector<GLfloat>* objectVertices;
		vector<GLuint>* objectIndices;
		vector<glm::vec3>* objectNormals;

		void updateVertices(vector<GLfloat>* inputVertices);	// Update Vertices
		void updateIndices(vector<GLuint>* inputIndices);		// Update Indices
		void updateNormals(vector<glm::vec3>* inputNormals);	// Update Normals
};