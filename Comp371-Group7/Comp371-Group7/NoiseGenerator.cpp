#include "NoiseGenerator.h"
#include <random>
#include <iostream>


NoiseGenerator::NoiseGenerator()
{
	std::random_device rd;					//obtain a random number from hardware
	std::mt19937 eng(rd());					// seed the generator
	std::uniform_real_distribution<> distr(2.3, 2.6);	// define the range
	this->randomOctaves = 4;
	this->randomPersistance = distr(eng);
}

NoiseGenerator::~NoiseGenerator()
{
}
