#pragma once
#include "CommonLibrary.h"
#include <math.h>
#include <iostream>
#include <random>
#include "PerlinNoise.h"

class NoiseGenerator
{
public:
	NoiseGenerator();
	~NoiseGenerator();


	//Generates a random value between 0 and 1;
	static float genNoise(float x, float y) {
		int n = (int)(x + y * 573);
		n = (n << 13) ^ n;
		return(1.0f - ((n*(n*n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0f);
	}

	//Function to interpolate
	static float lerp(float a, float b, float x) { // Linear Interpolation
		return a*(1 - x) + b*x;
	}
	static float cosineInterpolate(float a, float b, float x) { // (Better looking noise)
		float ft = x*3.1415927f;
		float f = (1 - (float)cos(ft)) * 0.5f;

		return a*(1 - f) + b*f;
	}

	static float smoothNoise(float x, float y) {
		x = (int)x;
		float corners = (genNoise(x - 1, y - 1) + genNoise(x + 1, y - 1) + genNoise(x - 1, y + 1) + genNoise(x + 1, y + 1)) / 16.0f;
		float sides = (genNoise(x - 1, y) + genNoise(x + 1, y) + genNoise(x, y - 1) + genNoise(x, y + 1)) / 8.0f;
		float center = genNoise(x, y) / 4.0f;

		return corners + sides + center;
	}

	static float interpolatedNoise(float x, float y) {
		int intX = (int)x;
		float fractionX = x - intX;

		int intY = (int)y;
		float fractionY = y - intY;

		float v1 = smoothNoise(intX, intY);
		float v2 = smoothNoise(intX + 1, intY);
		float v3 = smoothNoise(intX, intY + 1);
		float v4 = smoothNoise(intX + 1, intY + 1);

		// Interpolate them in 2d
		float i1 = cosineInterpolate(v1, v2, fractionX);
		float i2 = cosineInterpolate(v3, v4, fractionX);

		return cosineInterpolate(i1, i2, fractionY);
	}

	float perlinNoise(float x, float y) {
		float total = 0;
		float p = randomPersistance;									// Persistance    (Roughness of the Plane)
		int n = randomOctaves;											// Number of OCTAVES 

																		// Loops how many octaves you want in the noise
		for (int i = 0; i < n; i++) {
			float frequency = pow(2, i) / 128.0f;
			float amplitude = pow(p, i);

			total += interpolatedNoise(x * frequency, y*frequency) * amplitude;
		}

		return total;
	}

	//Overloading PerlinNoise for biomes
	static float perlinNoise(float x, float y, float p, int n) {
		float total = 0;
		for (int i = 0; i < n; i++) {
			float frequency = pow(2, i) / 128.0f;
			float amplitude = pow(p, i);

			total += interpolatedNoise(x * frequency, y*frequency) * amplitude;
		}

		return total;
	}

	static float ridged_Multifractal(float x, float y) {
		float total = 0;
		float p = 0.4f;
		int n = 9;
		for (int i = 0; i < n; i++) {
			float frequency = (float)pow(2.0f, i) / 128.0f;
			float amplitude = (float)pow(p, i);

			float signal = interpolatedNoise(x *frequency, y*frequency);
			signal /= signal + 1.0f;
			total += abs(signal*amplitude);
		}
		return total;
	}
private:
	float randomPersistance = 2.0f;
	int randomOctaves;
};

