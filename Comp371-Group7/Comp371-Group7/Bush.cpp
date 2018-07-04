#include "Bush.h"

// Icosahedron characteristic coordinates
#define X .525731112119133606
#define Z .850650808352039932


// Parameterized constructor
Bush::Bush(float u, float randomX, float setY, float randomZ, glm::vec3 color) {

		// ================ Vertex #1 ================
		localVertices.push_back((-X + randomX) * u);
		localVertices.push_back(setY * u);
		localVertices.push_back((Z + randomZ) * u);

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
		localVertices.push_back((X + randomX) * u);
		localVertices.push_back(setY * u);
		localVertices.push_back((Z + randomZ) * u);

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
		localVertices.push_back((-X + randomX) * u);
		localVertices.push_back(setY * u);
		localVertices.push_back((-Z + randomZ) * u );

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
		localVertices.push_back((X + randomX) * u);
		localVertices.push_back(setY * u);
		localVertices.push_back((-Z + randomZ) * u);

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
		localVertices.push_back(randomX * u);
		localVertices.push_back((Z + setY) * u);
		localVertices.push_back((X + randomZ) * u);

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
		localVertices.push_back(randomX * u );
		localVertices.push_back((Z + setY) * u );
		localVertices.push_back((-X + randomZ) * u);

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
		localVertices.push_back(randomX * u );
		localVertices.push_back((-Z + setY) * u);
		localVertices.push_back((X + randomZ) * u );

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
		localVertices.push_back(randomX * u );
		localVertices.push_back((-Z + setY) * u );
		localVertices.push_back((-X + randomZ) * u );

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
		localVertices.push_back((Z + randomX) * u );
		localVertices.push_back((X + setY) * u );
		localVertices.push_back(randomZ * u );

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
		localVertices.push_back((-Z + randomX) * u );
		localVertices.push_back((X + setY) * u );
		localVertices.push_back(randomZ * u );

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
		localVertices.push_back((Z + randomX) * u );
		localVertices.push_back((-X + setY) * u );
		localVertices.push_back(randomZ * u );

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
		localVertices.push_back((-Z + randomX) * u );
		localVertices.push_back((-X + setY) * u );
		localVertices.push_back(randomZ * u );

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

		// =============== Local indices =============== 
		localIndices.push_back(1);
		localIndices.push_back(4);
		localIndices.push_back(0);

		localIndices.push_back(4);
		localIndices.push_back(9);
		localIndices.push_back(0);

		localIndices.push_back(4);
		localIndices.push_back(5);
		localIndices.push_back(9);

		localIndices.push_back(8);
		localIndices.push_back(5);
		localIndices.push_back(4);

		localIndices.push_back(1);
		localIndices.push_back(8);
		localIndices.push_back(4);

		localIndices.push_back(1);
		localIndices.push_back(10);
		localIndices.push_back(8);

		localIndices.push_back(10);
		localIndices.push_back(3);
		localIndices.push_back(8);

		localIndices.push_back(8);
		localIndices.push_back(3);
		localIndices.push_back(5);

		localIndices.push_back(3);
		localIndices.push_back(2);
		localIndices.push_back(5);

		localIndices.push_back(3);
		localIndices.push_back(7);
		localIndices.push_back(2);

		localIndices.push_back(3);
		localIndices.push_back(10);
		localIndices.push_back(7);

		localIndices.push_back(10);
		localIndices.push_back(6);
		localIndices.push_back(7);

		localIndices.push_back(6);
		localIndices.push_back(11);
		localIndices.push_back(7);

		localIndices.push_back(6);
		localIndices.push_back(0);
		localIndices.push_back(11);

		localIndices.push_back(6);
		localIndices.push_back(1);
		localIndices.push_back(0);

		localIndices.push_back(10);
		localIndices.push_back(1);
		localIndices.push_back(6);

		localIndices.push_back(11);
		localIndices.push_back(0);
		localIndices.push_back(9);

		localIndices.push_back(2);
		localIndices.push_back(11);
		localIndices.push_back(9);

		localIndices.push_back(5);
		localIndices.push_back(2);
		localIndices.push_back(9);

		localIndices.push_back(11);
		localIndices.push_back(2);
		localIndices.push_back(7);
	
		int offset = 6;
		// =============== Local Normals =============== 
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
Bush::~Bush() {
}

// Getter: Get Local Vertices
vector<GLfloat>* Bush::getVertices() {
	return &localVertices;
}

// Getter: Get Local Indices
vector<GLuint>* Bush::getIndices() {
	return &localIndices;
}

// Getter: Get Local Normals
vector<glm::vec3>* Bush::getNormals() {
	return &localNormals;
}
