#include "Cube.h"


// Parameterized constructor
Cube::Cube(float u, float randomX, float setY, float randomZ, glm::vec3 color) {
	
	int size = localVertices.size() / 9;

	// ================ Vertex #1 ================
	localVertices.push_back((-1 + randomX) * u);
	localVertices.push_back((-1 + setY) * u);
	localVertices.push_back((1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #2 ================
	localVertices.push_back((1 + randomX) * u);
	localVertices.push_back((-1 + setY) * u);
	localVertices.push_back((1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #3 ================
	localVertices.push_back((1 + randomX) * u);
	localVertices.push_back((1 + setY) * u);
	localVertices.push_back((1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #4 ================
	localVertices.push_back((-1 + randomX) * u);
	localVertices.push_back((1 + setY) * u);
	localVertices.push_back((1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #5 ================
	localVertices.push_back((1 + randomX) * u);
	localVertices.push_back((1 + setY) * u);
	localVertices.push_back((1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #6 ================
	localVertices.push_back((1 + randomX) * u);
	localVertices.push_back((1 + setY) * u);
	localVertices.push_back((-1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #7 ================
	localVertices.push_back((1 + randomX) * u);
	localVertices.push_back((-1 + setY) * u);
	localVertices.push_back((-1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #8 ================
	localVertices.push_back((1 + randomX) * u);
	localVertices.push_back((-1 + setY) * u);
	localVertices.push_back((1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #9 ================
	localVertices.push_back((-1 + randomX) * u);
	localVertices.push_back((-1 + setY) * u);
	localVertices.push_back((-1  + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #10 ================
	localVertices.push_back((1 + randomX) * u);
	localVertices.push_back((-1 + setY) * u);
	localVertices.push_back((-1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #11 ================
	localVertices.push_back((1 + randomX) * u);
	localVertices.push_back((1 + setY) * u);
	localVertices.push_back((-1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #12 ================
	localVertices.push_back((-1 + randomX) * u);
	localVertices.push_back((1 + setY) * u);
	localVertices.push_back((-1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #13 ================
	localVertices.push_back((-1 + randomX) * u);
	localVertices.push_back((-1 + setY) * u);
	localVertices.push_back((-1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #14 ================
	localVertices.push_back((-1 + randomX) * u);
	localVertices.push_back((-1 + setY) * u);
	localVertices.push_back((1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #15 ================
	localVertices.push_back((-1 + randomX) * u);
	localVertices.push_back((1 + setY) * u);
	localVertices.push_back((1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #16 ================
	localVertices.push_back((-1 + randomX) * u);
	localVertices.push_back((1 + setY) * u);
	localVertices.push_back((-1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #17 ================
	localVertices.push_back((1 + randomX) * u);
	localVertices.push_back((1 + setY) * u);
	localVertices.push_back((1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #18 ================
	localVertices.push_back((-1 + randomX) * u);
	localVertices.push_back((1 + setY) * u);
	localVertices.push_back((1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #19 ================
	localVertices.push_back((-1 + randomX) * u);
	localVertices.push_back((1 + setY) * u);
	localVertices.push_back((-1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #20 ================
	localVertices.push_back((1 + randomX) * u);
	localVertices.push_back((1 + setY) * u);
	localVertices.push_back((-1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #21 ================
	localVertices.push_back((-1 + randomX) * u);
	localVertices.push_back((-1 + setY) * u);
	localVertices.push_back((-1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #22 ================
	localVertices.push_back((1 + randomX) * u);
	localVertices.push_back((-1 + setY) * u);
	localVertices.push_back((-1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #23 ================
	localVertices.push_back((1 + randomX) * u);
	localVertices.push_back((-1 + setY) * u);
	localVertices.push_back((1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);

	// ================ Vertex #24 ================
	localVertices.push_back((-1 + randomX) * u);
	localVertices.push_back((-1 + setY) * u);
	localVertices.push_back((1 + randomZ) * u);

	// Adding Color Vertices
	randomColorOffset = rand() % 10 + 1;
	localVertices.push_back(color.x + ((float)randomColorOffset / 100));
	localVertices.push_back(color.y + ((float)randomColorOffset / 100));
	localVertices.push_back(color.z + ((float)randomColorOffset / 100));

	// Texture Coordinates
	localVertices.push_back(0.0);
	localVertices.push_back(0.0);
	// Opacity
	localVertices.push_back(2.0);


	// =============== Local Indices =============== 
	localIndices.push_back(0);
	localIndices.push_back(1);
	localIndices.push_back(2);

	localIndices.push_back(0);
	localIndices.push_back(2);
	localIndices.push_back(3);

	localIndices.push_back(4);
	localIndices.push_back(5);
	localIndices.push_back(6);

	localIndices.push_back(4);
	localIndices.push_back(6);
	localIndices.push_back(7);

	localIndices.push_back(8);
	localIndices.push_back(9);
	localIndices.push_back(10);

	localIndices.push_back(8);
	localIndices.push_back(10);
	localIndices.push_back(11);

	localIndices.push_back(12);
	localIndices.push_back(13);
	localIndices.push_back(14);

	localIndices.push_back(12);
	localIndices.push_back(14);
	localIndices.push_back(15);

	localIndices.push_back(16);
	localIndices.push_back(17);
	localIndices.push_back(18);

	localIndices.push_back(16);
	localIndices.push_back(18);
	localIndices.push_back(19);

	localIndices.push_back(20);
	localIndices.push_back(21);
	localIndices.push_back(22);

	localIndices.push_back(20);
	localIndices.push_back(22);
	localIndices.push_back(23);

	// =============== Local Normals ===============
	for (int i = 0; i < localIndices.size(); i += 3) {
		vector1 = glm::vec3(localVertices[localIndices[i + 1]] - localVertices[localIndices[i]],
			localVertices[localIndices[i + 1] + 1] - localVertices[localIndices[i] + 1],
			localVertices[localIndices[i + 1] + 2] - localVertices[localIndices[i] + 2]);
		vector2 = glm::vec3(localVertices[localIndices[i + 2]] - localVertices[localIndices[i]],
			localVertices[localIndices[i + 2] + 1] - localVertices[localIndices[i] + 1],
			localVertices[localIndices[i + 2] + 2] - localVertices[localIndices[i] + 2]);
		vectorProduct = cross(vector1, vector2);
		localNormals.push_back(normalize(vectorProduct));
	}
	
}

// Destructor
Cube::~Cube() {
}

// Getter: Get Local Vertices
vector<GLfloat>* Cube::getVertices() {
	return &localVertices;
}

// Getter: Get Local Indices
vector<GLuint>* Cube::getIndices() {
	return &localIndices;
}

// Getter: Get Local Normals
vector<glm::vec3>* Cube::getNormals() {
	return &localNormals;
}