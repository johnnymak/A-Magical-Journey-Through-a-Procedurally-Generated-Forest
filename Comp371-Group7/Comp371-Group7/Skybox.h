#pragma once

#include "CommonLibrary.h"
#include "Shaders/Shader.h"

#include "Camera.h"

class Skybox {

public:
	Skybox();
	Skybox(Shader* shader);
	~Skybox();

	void loadCubeMap(vector<GLchar*> fileLocation);
	void draw(Camera* cam, glm::mat4* view, glm::mat4* projection);

private:
	vector<GLfloat>* localVertices;
	Shader* localShader;

	GLuint skyboxVAO, skyboxVBO, textureID;

};