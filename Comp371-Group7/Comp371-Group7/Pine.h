#pragma once

#include "RotationalObject.h"

class Pine {

	public:

		Pine(float u, float ranx, float rany, float ranz, glm::vec3 color) {
			float x, y, z;
			int rotationSpan = 5;
		
			u /= 2*UNIT;
			GLfloat originalVertices[] = {
				-1.00 * u * UNIT, 0.50 * u * UNIT, 0.0,
				-0.38 * u * UNIT, 1.00 * u * UNIT, 0.0,
				-0.75 * u * UNIT, 0.95 * u * UNIT, 0.0,
				-0.25 * u * UNIT, 1.50 * u * UNIT, 0.0,
				-0.50 * u * UNIT, 1.50 * u * UNIT, 0.0,
				-0.00 * u * UNIT, 2.00 * u * UNIT, 0.0, };

			RotationalObject obj;
			u = 1.0;
			for (int i = 0; i < 18 - 2; i += 3) {
				obj.addProfileCurve(originalVertices[i], originalVertices[i + 1], originalVertices[i + 2]);
			}

			profileCurveLength = obj.getProfileCurveSize();
			trajectoryCurveLength = rotationSpan;

			// Rotates the vertices
			for (int i = 0; i <= rotationSpan; i++) {
				for (int j = 0; j < obj.getProfileCurveSize(); j++) {
					if (i == 0) {
						localVertices.push_back((obj.getProfileCurveCoordinates(j).x + ranx) * u);
						localVertices.push_back((obj.getProfileCurveCoordinates(j).y) + rany);
						localVertices.push_back((obj.getProfileCurveCoordinates(j).z + ranz) * u);

						// Color offset 
						randomColorOffset = rand() % 5 + 1;

						// Adding Color Vertices
						localVertices.push_back(color.x + ((float)randomColorOffset / 100));
						localVertices.push_back(color.y + ((float)randomColorOffset / 100));
						localVertices.push_back(color.z + ((float)randomColorOffset / 100));

						// Texture Coordinates
						localVertices.push_back(0.0);
						localVertices.push_back(0.0);
						// Opacity
						localVertices.push_back(2.0);
					}
					else {
						glm::vec4 rotatedvertex;
						glm::mat4 rotate;
						rotate = glm::rotate(rotate, glm::radians((float)(360 / rotationSpan)), glm::vec3(0.0f, 1.0f, 0.0f));

						rotatedvertex = rotate * obj.getProfileCurveCoordinates(j);
			
						localVertices.push_back(((ceil(rotatedvertex.x * 100) / 100) + ranx) * u);
						localVertices.push_back((ceil(rotatedvertex.y * 100) / 100) + rany);
						localVertices.push_back(((ceil(rotatedvertex.z * 100) / 100) + ranz) * u);

						// Color offset 
						randomColorOffset = rand() % 5 + 1;


						// Adding Color Vertices
						localVertices.push_back(color.x + ((float)randomColorOffset / 100));
						localVertices.push_back(color.y + ((float)randomColorOffset / 100));
						localVertices.push_back(color.z + ((float)randomColorOffset / 100));

						// Texture Coordinates
						localVertices.push_back(0.0);
						localVertices.push_back(0.0);
						// Opacity
						localVertices.push_back(2.0);

						obj.setNewProfileCurveVertex(j, rotatedvertex);
					}
				}
			}
		
			// Push back indices
			for (int k = 0; k < trajectoryCurveLength; k++) {
				for (int i = 1; i < profileCurveLength; i++) {
					localIndices.push_back(pushValueLimit((GLuint)(i - 1 + (profileCurveLength * k))));
					localIndices.push_back(pushValueLimit((GLuint)(i + (profileCurveLength * k))));
					localIndices.push_back(pushValueLimit((GLuint)(i - 1 + profileCurveLength + (profileCurveLength * k))));
					localIndices.push_back(pushValueLimit((GLuint)(i + (profileCurveLength * k))));
					localIndices.push_back(pushValueLimit((GLuint)(i + profileCurveLength + (profileCurveLength * k)))); // 5th
					localIndices.push_back(pushValueLimit((GLuint)(i - 1 + profileCurveLength + (profileCurveLength * k)))); // 6th
				}
			}

			// NOTE: CHANGED ALL VALUES DOWN HERE FROM 6 to 9, CHANGE BACK IF THERE ARE PROBLEMS
			int offset = 9;
			// Push back normals 
			for (int i = 0; i < localIndices.size(); i += 3) {
				vector1 = glm::vec3(localVertices[localIndices[i + 1] * offset] - localVertices[localIndices[i] * offset],
					localVertices[localIndices[i + 1] * offset + 1] - localVertices[localIndices[i] * offset + 1],
					localVertices[localIndices[i + 1] * offset + 2] - localVertices[localIndices[i] * offset + 2]);
				vector2 = glm::vec3(localVertices[localIndices[i + 2] * offset] - localVertices[localIndices[i] * offset],
					localVertices[localIndices[i + 2] * offset + 1] - localVertices[localIndices[i] * offset + 1],
					localVertices[localIndices[i + 2] * offset + 2] - localVertices[localIndices[i] * offset + 2]);
				vectorProduct = cross(vector1, vector2);
				localNormals.push_back(normalize(vectorProduct));
			}
		};

		Pine() {};
		~Pine() { };

		// Getter: Get Local Vertices
		vector<GLfloat>* getVertices() { return &localVertices; }

		// Getter: Get Local Indices
		vector<GLuint>* getIndices() { return &localIndices; }

		// Getter: Get Local Normals
		vector<glm::vec3>* getNormals() { return &localNormals; }

	private:
		int profileCurveLength;
		int trajectoryCurveLength;
		int randomColorOffset;
		glm::vec3 vector1;
		glm::vec3 vector2;
		glm::vec3 vectorProduct;
		vector<GLfloat> localVertices;
		vector<GLuint> localIndices;
		vector<glm::vec3> localNormals;

		// Function to limit the indices for the mesh to connect the end with the front 
		GLfloat pushValueLimit(GLuint value) {
			if (value >= (profileCurveLength * (trajectoryCurveLength)))
				return value - (profileCurveLength * (trajectoryCurveLength));
			return value;
		}
};