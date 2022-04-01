#pragma once

#include <ctime>
#include <random>


inline int static randomInt(int min, int max)
{
	//srand(time(0));
	return (rand() % max) + min;//min + (std::rand() % (max - min + 1));
}

static float dist(const sf::Vector2f p1, const sf::Vector2f p2)
{
	float diffY = p1.y - p2.y;
	float diffX = p1.x - p2.x;
	return sqrt((diffY * diffY) + (diffX * diffX));
}

inline float static randomFloat(float min, float max)
{
	//srand(static_cast<unsigned>(time(0)));
	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(max-min)));
}