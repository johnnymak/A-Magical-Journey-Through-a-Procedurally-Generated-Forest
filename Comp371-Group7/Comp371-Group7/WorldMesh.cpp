
#include "WorldMesh.h"
#include "NoiseGenerator.h"
#include "Mountains.h"
#include "Plains.h"
// ==================== Constructor ==================== //
WorldMesh::WorldMesh() : vertexManager(&vertices, &indices, &normals) {

	/*
		=========================================================================== 
									Creating Meshes
			You can use this entire section to create the objects to be drawn
		=========================================================================== 
	*/


	// ======= Creating the Grid ======= //
	Grid plane(UNIT, GRID_SIZE, GRASS_COLOR);
	NoiseGenerator perlinNoise = NoiseGenerator();
	
	// Generate Terrain Height with Perlin Noise
	for (int x = 0; x < plane.getGridSize(); x++) {
		for (int y = 0; y < plane.getGridSize(); y++) {
			plane.setVertexY(x, y, perlinNoise.perlinNoise(x, y));
		}
	}
	
	// Adding Dirt Patches onto the Terrain
	int numOfDirtPatch = rand() % 40 + 20;
	int coordX;
	int coordY;

	for (int patch = 0; patch < numOfDirtPatch; patch++) {
		coordX = rand() % (GRID_SIZE * 2 - 100) + 20;
		coordY = rand() % (GRID_SIZE * 2 - 100) + 20;

		plane.addDirtPatch(coordX, coordY);
	}

	// Sending the terrain to the Vertex Manager
	vertexManager.updateMeshes(plane.getVertices(), plane.getIndices(), plane.getNormals());



	// Global variables used to make our objects
	glm::vec3 center;
	int randomX, randomY, randomZ, min, max;
	int treeCount = GRID_SIZE / 3;
	float scale;

	// ========================= MAPLE TREES ========================= //
	min = -plane.getGridSize() / (2 / UNIT);
	max = plane.getGridSize() / (2 / UNIT);
	
	for (int i = 0; i < treeCount; i++) {
		do {
			scale = 3.0 * UNIT * (0.5 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX) / (2.1)));
		} while (scale >= 4.0 && scale <= 3.0);

		randomX = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max - min) + min;
		randomY = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max / 8 - min / 8) - min / 8;
		randomZ = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max - min) + min;

		center = glm::vec3(randomX, randomY, randomZ);

		randomX = randomX / 2 + GRID_SIZE;
		randomZ = randomZ / 2 + GRID_SIZE;
		center.y = plane.getVertex(randomX, randomZ).y;

		MapleTree tree(scale, center);

		vertexManager.updateMeshes(tree.getTop()->getVertices(), tree.getTop()->getIndices(), tree.getTop()->getNormals());
		vertexManager.updateMeshes(tree.getTrunk()->getVertices(), tree.getTrunk()->getIndices(), tree.getTrunk()->getNormals());
	}

	// ========================= PINE TREES ========================= //
	for (int i = 0; i < treeCount; i++) {
		min = -plane.getGridSize() / (2 / UNIT);
		max = plane.getGridSize() / (2 / UNIT);
		randomX = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max - min) + min;
		randomY = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max / 8 - min / 8) - min / 8;
		randomZ = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max - min) + min;
		do {
			scale = 3.0 * UNIT * (0.5 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX) / (2.5)));
		} while (scale >= 4.0 && scale <= 3.0);

		center = glm::vec3(randomX, randomY, randomZ);

		randomX = randomX / 2 + GRID_SIZE;
		randomZ = randomZ / 2 + GRID_SIZE;
		center.y = plane.getVertex(randomX, randomZ).y;

		PineTree tree(scale, center);
		vertexManager.updateMeshes(tree.getTrunk()->getVertices(), tree.getTrunk()->getIndices(), tree.getTrunk()->getNormals());
		vertexManager.updateMeshes(tree.getTop()->getVertices(), tree.getTop()->getIndices(), tree.getTop()->getNormals());
	}

	// ========================= CLOUDS ========================= //
	int num = GRID_SIZE / 5;
	// min and max are left and right edges of the grid - note that min is negative
	min = -plane.getGridSize() / (2 / UNIT);
	max = plane.getGridSize() / (2 / UNIT);
	for (int i = 0; i < num; i++) {
		scale = 8.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - 0.1)));

		randomX = scale * (static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max - min) + min); // eeeiiiillle ça marche avec multiplication
		randomY = (static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max / 8 - min / 8) - min / 8); // sérieux wtf
		randomZ = scale * (static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max - min) + min);

		center = glm::vec3(randomX/scale, randomY, randomZ/scale);

		Cloud cl(scale, center);
		vertexManager.updateMeshes(cl.getVertices(), cl.getIndices(), cl.getNormals());
	}


	// ========================= BUSHES ========================= //
	num = GRID_SIZE / 3;
	for (int i = 0; i < num; i++) {
		scale = (float)(rand() % 8 + 5) + 0.1 * (float)(rand() % 10 + 1);
		randomX = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max - min) + min;
		randomY = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max / 8 - min / 8) - min / 8;
		randomZ = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max - min) + min;
		glm::vec3 bcolor = glm::vec3(1.0f, 0.0f, 0.0f);

		float tempRandomX = randomX / 2 + GRID_SIZE;
		float tempRandomZ = randomZ / 2 + GRID_SIZE;

		center.y = plane.getVertex(tempRandomX, tempRandomZ).y;

		Bush b(scale, randomX / scale, 1.0 / scale, randomZ / scale, BUSH_COLOR);
		vertexManager.updateMeshes(b.getVertices(), b.getIndices(), b.getNormals());
	}

	// =========================  ROCKS ========================= //
	num = GRID_SIZE / 3;
	for (int i = 0; i < num; i++) {
		//scale = 3.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - 0.1)));
		scale = (float)(rand() % 5 + 1) + 0.1 * (float)(rand() % 10 + 1);
		randomX = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max - min) + min;
		// height y is based off of grid size but way smaller than x and z so that we can see the clouds near the top of trees
		randomY = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max / 8 - min / 8) - min / 8;
		randomZ = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX + 1)) * (max - min) + min;

		float tempRandomX = randomX / 2 + GRID_SIZE;
		float tempRandomZ = randomZ / 2 + GRID_SIZE;

		center.y = plane.getVertex(tempRandomX, tempRandomZ).y;

		Bush b(scale, randomX / scale, center.y / scale, randomZ / scale, ROCK_COLOR);
		vertexManager.updateMeshes(b.getVertices(), b.getIndices(), b.getNormals());
	}
}

// Destructor
WorldMesh::~WorldMesh() { }