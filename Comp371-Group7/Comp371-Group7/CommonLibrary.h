
#define _CRT_NONSTDC_NO_WARNINGS // DO NOT DELETE, IMPORTANT !
#pragma warning(disable:4996) // DO NOT DELETE, IMPORTANT !
#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>


// GLEW 
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// SOIL
#include <Soil/SOIL.h>


// Window dimensions (1200x800) 
const GLuint WIDTH = 1440,
			HEIGHT = 900;


// ================================== Object Colors ================================== 


// Brightness Constant: Change this value if the color are good and you want to 
//                      adjust the brightness of the world alltogether
const int COLOR_BRIGHTNESS = 10;

// Bush Colour RBG
const int BUSH_COLOR_R = 145;
const int BUSH_COLOR_G = 232;
const int BUSH_COLOR_B = 16;


// Cloud Color RGB
const int CLOUD_COLOR_R = 235;
const int CLOUD_COLOR_G = 237;
const int CLOUD_COLOR_B = 242;

// Mountain Color RGB
const int MOUNTAIN_COLOR_R = 134;
const int MOUNTAIN_COLOR_G = 144;
const int MOUNTAIN_COLOR_B = 179;

// Water Color RGB
const int WATER_COLOR_R = 114;
const int WATER_COLOR_G = 172;
const int WATER_COLOR_B = 255;

// Maple Tree Color RGB
//const int MAPLETREE_COLOR_R = 119;
//const int MAPLETREE_COLOR_G = 173;
//const int MAPLETREE_COLOR_B = 27;
const int MAPLETREE_COLOR_R = 255;
const int MAPLETREE_COLOR_G = 81;
const int MAPLETREE_COLOR_B = 81;


// Trunk Color RGB
const int TRUNK_COLOR_R = 178;
const int TRUNK_COLOR_G = 94;
const int TRUNK_COLOR_B = 58;

// Pine Tree Color RGB
const int PINETREE_COLOR_R = 59;
const int PINETREE_COLOR_G = 196;
const int PINETREE_COLOR_B = 112;

// Grass Color RGB
const int GRASS_COLOR_R = 116;
const int GRASS_COLOR_G = 204;
const int GRASS_COLOR_B = 73;

// Dirt Color RGB
const int DIRT_COLOR_R = 232;
const int DIRT_COLOR_G = 211;
const int DIRT_COLOR_B = 146;

// Rock Color RGB
const int ROCK_COLOR_R = 134;
const int ROCK_COLOR_G = 144;
const int ROCK_COLOR_B = 179;



// Function to find Float values given color values (0 - 255)
inline float getFloatColor(int colorValue) {

	colorValue += COLOR_BRIGHTNESS;

	if (colorValue >= 0 && colorValue <= 255)
		return ((float)colorValue / (float)255);

	else if (colorValue > 255)
		return 1.0f;

	return 0.0f;
};

// Bush Color
const glm::vec3 BUSH_COLOR(getFloatColor(BUSH_COLOR_R), getFloatColor(BUSH_COLOR_G), getFloatColor(BUSH_COLOR_B));

// Cloud Color
const glm::vec3 CLOUD_COLOR(getFloatColor(CLOUD_COLOR_R), getFloatColor(CLOUD_COLOR_G), getFloatColor(CLOUD_COLOR_B));

// Moutain Color
const glm::vec3 MOUNTAIN_COLOR(getFloatColor(MOUNTAIN_COLOR_R), getFloatColor(MOUNTAIN_COLOR_G), getFloatColor(MOUNTAIN_COLOR_B));

// Water Color
const glm::vec3 WATER_COLOR(getFloatColor(WATER_COLOR_R), getFloatColor(WATER_COLOR_G), getFloatColor(WATER_COLOR_B));

// Maple Tree Color
const glm::vec3 MAPLETREE_COLOR(getFloatColor(MAPLETREE_COLOR_R), getFloatColor(MAPLETREE_COLOR_G), getFloatColor(MAPLETREE_COLOR_B));

// Trunk  Color 
const glm::vec3 TRUNK_COLOR(getFloatColor(TRUNK_COLOR_R), getFloatColor(TRUNK_COLOR_G), getFloatColor(TRUNK_COLOR_B));

// Pine Tree Color
const glm::vec3 PINETREE_COLOR(getFloatColor(PINETREE_COLOR_R), getFloatColor(PINETREE_COLOR_G), getFloatColor(PINETREE_COLOR_B));

// Grass Color
const glm::vec3 GRASS_COLOR(getFloatColor(GRASS_COLOR_R), getFloatColor(GRASS_COLOR_G), getFloatColor(GRASS_COLOR_B));

// Dirt Path Color
const glm::vec3 DIRT_PATH_COLOR(getFloatColor(DIRT_COLOR_R), getFloatColor(DIRT_COLOR_G), getFloatColor(DIRT_COLOR_B));

// Rock Color
const glm::vec3 ROCK_COLOR(getFloatColor(ROCK_COLOR_R), getFloatColor(ROCK_COLOR_G), getFloatColor(ROCK_COLOR_B));



// ================================== Object Sizes ================================== 

// Grid Unit Size (UNIT x UNIT Squares)
const GLfloat UNIT = 2.0f;

// Base Grid Size
const int GRID_SIZE = 200;


// Maple Tree Component Sizes
const float UNIT_MAPLETREE_TOP   = 4.0f;
const float UNIT_MAPLETREE_TRUNK = 1.0f;

// Pine Tree Component Sizes
const float UNIT_PINETREE_TOP   = 4.0f;
const float UNIT_PINETREE_TRUNK = 1.0f;

