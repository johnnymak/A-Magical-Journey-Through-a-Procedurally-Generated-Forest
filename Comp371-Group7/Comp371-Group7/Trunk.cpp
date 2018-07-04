#include "Trunk.h"
#include "Bush.h"
#include "RotationalObject.h"

Trunk::Trunk(float u, glm::vec3 center, glm::vec3 color) {
	float x, y, z;
	int rotationSpan = 8;
	vector<GLfloat> vertices;

	u /= 2*UNIT;
	
	// ======== vertices for trunks ======== //
	GLfloat ver1[] = {
		//x                             y                   z
		UNIT * u / 2                  , 0.0f              , 0.0f,
		(UNIT * u - 0.10 * UNIT) / 2  , UNIT * u / 2      , 0.0f,
		(UNIT * u - 0.18 * UNIT) / 2  , UNIT * u          , 0.0f,
		(UNIT * u - 0.30 * UNIT) / 2  , UNIT * u * 3 / 2  , 0.0f,
		(UNIT * u - 0.15 * UNIT) / 2  , UNIT * u * 2      , 0.0f,
		(UNIT * u - 0.28 * UNIT) / 2  , UNIT * u * 5 / 2  , 0.0f,
		(UNIT * u - 0.12 * UNIT) / 2  , UNIT * u * 3      , 0.0f, };

	RotationalObject obj;
	u = 1.0;
	
	for (int i = 0; i < 19; i += 3) {
		obj.addProfileCurve(ver1[i], ver1[i + 1], ver1[i + 2]);
	}
	
	
	profileCurveLength = obj.getProfileCurveSize();
	trajectoryCurveLength = rotationSpan;

	// Rotates the vertices
	for (int i = 0; i <= rotationSpan; i++) {
		for (int j = 0; j < obj.getProfileCurveSize(); j++) {
			if (i == 0) {
				vertices.push_back((obj.getProfileCurveCoordinates(j).x + center.x) * u);
				vertices.push_back((obj.getProfileCurveCoordinates(j).y) + center.y);
				vertices.push_back((obj.getProfileCurveCoordinates(j).z + center.z) * u);

				// Color offset 
				randomColorOffset = rand() % 5 + 1;

				// Adding Color Vertices
				vertices.push_back(color.x + ((float)randomColorOffset / 100));
				vertices.push_back(color.y + ((float)randomColorOffset / 100));
				vertices.push_back(color.z + ((float)randomColorOffset / 100));

				// Texture Coordinates
				vertices.push_back(0.0);
				vertices.push_back(0.0);
				// Opacity
				vertices.push_back(2.0);
			}
			else {
				glm::vec4 rotatedvertex;
				glm::mat4 rotate;
				rotate = glm::rotate(rotate, glm::radians((float)(360 / rotationSpan)), glm::vec3(0.0f, 1.0f, 0.0f));

				rotatedvertex = rotate * obj.getProfileCurveCoordinates(j);

				vertices.push_back(((ceil(rotatedvertex.x * 100) / 100) + center.x) * u);
				vertices.push_back((ceil(rotatedvertex.y * 100) / 100) + center.y);
				vertices.push_back(((ceil(rotatedvertex.z * 100) / 100) + center.z) * u);

				// Color offset 
				randomColorOffset = rand() % 5 + 1;

				// Adding Color Vertices
				vertices.push_back(color.x + ((float)randomColorOffset / 100));
				vertices.push_back(color.y + ((float)randomColorOffset / 100));
				vertices.push_back(color.z + ((float)randomColorOffset / 100));

				// Texture Coordinates
				vertices.push_back(0.0);
				vertices.push_back(0.0);
				// Opacity
				vertices.push_back(2.0);

				obj.setNewProfileCurveVertex(j, rotatedvertex);
			}
		}
	}

	// push back vertices
	for (int i = 0; i < vertices.size(); i++) {
		localVertices.push_back(vertices.at(i));
	}

	// push back indices
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

	int offset = 9;
	// push back normals
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
}

// Destructor
Trunk::~Trunk() {
}

// Getter: Get Local Vertices
vector<GLfloat>* Trunk::getVertices() { return &localVertices; }

// Getter: Get Local Indices
vector<GLuint>* Trunk::getIndices() { return &localIndices; }

// Getter: Get Local Normals
vector<glm::vec3>* Trunk::getNormals() { return &localNormals; }

// Function to limit the indices for the mesh to connect the end with the front 
GLfloat Trunk::pushValueLimit(GLuint value) {
	if (value >= (profileCurveLength * (trajectoryCurveLength)))
		return value - (profileCurveLength * (trajectoryCurveLength));
	return value;
}