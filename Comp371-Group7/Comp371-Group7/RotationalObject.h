
#pragma once

#ifndef ROTATIONAL_OBJECT_H
#define ROTATIONAL_OBJECT_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

// GLEW 
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class RotationalObject {

public:

	// Constructor
	RotationalObject() { }

	// Adds coordinate to the profile curve
	void addProfileCurve(float x, float y, float z) {
		glm::vec4 vec(x, y, z, 1.0f);
		profileCurve.push_back(vec);
	}

	// GETTERS
	float getXCoordinate(int index) {
		return profileCurve.at(index).x;
	}

	float getYCoordinate(int index) {
		return profileCurve.at(index).y;
	}

	float getZCoordinate(int index) {
		return profileCurve.at(index).z;
	}

	int getProfileCurveSize() {
		return profileCurve.size();
	}


	glm::vec4 getProfileCurveCoordinates(int index) {
		return profileCurve.at(index);
	}

	glm::vec4 getLastProfileCurveCoordinates() {
		return profileCurve.at(profileCurve.size() - 1);
	}

	// SETTERS
	void setNewProfileCoordX(int index, GLfloat value) {
		profileCurve.at(index).x = value;
	}

	void setNewProfileCoordY(int index, GLfloat value) {
		profileCurve.at(index).y = value;
	}

	void setNewProfileCoordZ(int index, GLfloat value) {
		profileCurve.at(index).z = value;
	}

	void setNewProfileCurveVertex(int index, glm::vec4 value) {
		profileCurve.at(index) = value;
	}

	// TEST METHODS: Methods used for testing purposes
	float getElement(int index) {
		return profileCurve.at(index).y;
	}

	void printProfileCurve() {
		for (int i = 0; i< profileCurve.size(); ++i)
			cout << "Profile Curve Coordinate #" << i << ": " << profileCurve[i].x << ": " << profileCurve[i].y << ": " << profileCurve[i].z << endl;
	}


private:
	// Data Members
	vector<glm::vec4> profileCurve;


};

#endif