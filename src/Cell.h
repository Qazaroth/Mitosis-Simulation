#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include "Utils.h"

class Cell
{
private:
	sf::Vector2f pos = sf::Vector2f(0, 0);
	sf::Color c = sf::Color(randomInt(100, 255), 0, randomInt(100, 255), 255);

	float r = 60.0f;
public:
	Cell(sf::Window &window);
	Cell(sf::Vector2f p, float r=60.0f, sf::Color c=sf::Color(randomInt(100, 255), 0, randomInt(100, 255), 255));
	~Cell();

	bool clicked(sf::Vector2i pos);
	Cell mitosis();

	void move();
	void show(sf::RenderWindow &window);

	inline float getRadius() { return this->r; }
};

