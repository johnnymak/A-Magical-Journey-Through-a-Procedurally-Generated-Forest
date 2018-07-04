#pragma once
#include "Pine.h"
#include "Trunk.h"

class PineTree {
	public:
		PineTree() { }
		PineTree(float scale, glm::vec3 position) {
			trunk = Trunk((scale * UNIT_PINETREE_TRUNK), position, TRUNK_COLOR);
			float maxY = trunk.highestVertex();
			top = Pine(scale * UNIT_PINETREE_TOP, position.x, maxY / scale / UNIT_PINETREE_TOP / 1.5, position.z, PINETREE_COLOR);
		};

		Pine* getTop() { return &top; };
		Trunk* getTrunk() { return &trunk; };

	private:
		Trunk trunk;
		Pine top;
	};