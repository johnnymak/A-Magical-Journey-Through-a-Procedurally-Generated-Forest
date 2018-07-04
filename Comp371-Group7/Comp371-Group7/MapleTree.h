#pragma once
#include "CommonLibrary.h"
#include "Bush.h"
#include "Trunk.h"

class MapleTree {
	public:
		MapleTree() { }
		MapleTree(float scale, glm::vec3 position) {
			
			trunk = Trunk(scale , position, TRUNK_COLOR);

			float maxY = trunk.highestVertex();
			if (maxY < 1) maxY += 1;

			top = Bush(scale * 1.5, position.x / scale / 1.5, maxY / scale / 1.1, position.z / scale / 1.5, MAPLETREE_COLOR);

		};

		~MapleTree() {};

		Bush* getTop() { return &top; };
		Trunk* getTrunk() { return &trunk; };

	private:
		Bush top;
		Trunk trunk;
};
