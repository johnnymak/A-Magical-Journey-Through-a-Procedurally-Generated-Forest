#pragma once

#include "Bush.h"
#include "Trunk.h"

class Cloud {
public:
	Cloud(float scale, glm::vec3 position) {
		cloud1 = Bush((0.6 + scale), (1.0 * scale + position.x) / scale / 1.5, (2.5* scale + position.y) / scale / 1, position.z / scale / 1.5, CLOUD_COLOR);
		cloud2 = Bush((0.9 + scale), (1.8 * scale + position.x) / scale / 1.5, (2.6* scale + position.y) / scale / 1, position.z / scale / 1.5, CLOUD_COLOR);
		cloud3 = Bush((0.8 + scale), (2.8* scale + position.x) / scale / 1.5, (2.5 * scale + position.y) / scale / 1, position.z / scale / 1.5, CLOUD_COLOR);

		int size = localVertices.size() / 3;

		// =============== Local Vertices =============== 
		for (int i = 0; i < cloud1.getVertices()->size(); i++) {
			localVertices.push_back(cloud1.getVertices()->at(i));
		}
		for (int i = 0; i < cloud2.getVertices()->size(); i++) {
			localVertices.push_back(cloud2.getVertices()->at(i));
		}
		for (int i = 0; i < cloud3.getVertices()->size(); i++) {
			localVertices.push_back(cloud3.getVertices()->at(i));
		}

		// =============== Local Indices =============== 
		for (int i = 0; i < cloud1.getIndices()->size(); i++) {
			localIndices.push_back(cloud1.getIndices()->at(i) + size);
		}
		for (int i = 0; i < cloud2.getIndices()->size(); i++) {
			localIndices.push_back(cloud2.getIndices()->at(i) + cloud1.getIndices()->size() + size);
		}
		for (int i = 0; i < cloud3.getIndices()->size(); i++) {
			localIndices.push_back(cloud3.getIndices()->at(i) + cloud1.getIndices()->size() + cloud2.getIndices()->size() + size);
		}

		// =============== Local Normals =============== 
		for (int i = 0; i < cloud1.getNormals()->size(); i++) {
			localNormals.push_back(cloud1.getNormals()->at(i));
		}
		for (int i = 0; i < cloud2.getNormals()->size(); i++) {
			localNormals.push_back(cloud2.getNormals()->at(i));
		}
		for (int i = 0; i < cloud3.getNormals()->size(); i++) {
			localNormals.push_back(cloud3.getNormals()->at(i));
		}
	};
	~Cloud() { };
	vector<GLfloat>* getVertices() {
		return &localVertices;
	}
	vector<GLuint>* getIndices() {
		return &localIndices;
	}

	// Getter: Get Local Normals
	vector<glm::vec3>* getNormals() {
		return &localNormals;
	}

private:
	vector<GLfloat> localVertices;
	vector<GLuint> localIndices;
	vector<glm::vec3> localNormals;
	Bush cloud1, cloud2, cloud3;
};
