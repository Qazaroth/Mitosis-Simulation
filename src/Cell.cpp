#include "Cell.h"

Cell::Cell(sf::Window &window)
{
	//srand(time(0));

	sf::Vector2u size = window.getSize();

	unsigned int width = size.x;
	unsigned int height = size.y;

	this->pos.x = randomInt(0, width);
	this->pos.y = randomInt(0, height);

	int r = randomFloat(100, 255);
	int b = randomFloat(100, 255);

	sf::Color co(r, 0, b, 255);

	this->c = co;
}

Cell::Cell(sf::Vector2f p, float r, sf::Color c)
{
	this->pos = p;
	this->r = r;
	this->c = c;
}

Cell::~Cell() 
{}

bool Cell::clicked(sf::Vector2i kos)
{
	sf::Vector2f mPos = sf::Vector2f(kos.x, kos.y);
	float d = dist(this->pos, mPos);

	if (d < this->r) return true;

	return false;
}

Cell Cell::mitosis()
{
	Cell a(this->pos, this->r / 2, this->c);
	return a;
}

void Cell::move() 
{
	float x = randomFloat(-1.0f, 1.0f);
	float y = randomFloat(-1.0f, 1.0f);

	sf::Vector2f vel = sf::Vector2f(x, y);

	this->pos += vel;
}

void Cell::show(sf::RenderWindow &window) 
{
	sf::CircleShape c(this->r);
	c.setFillColor(this->c);
	c.setOrigin(c.getRadius(), c.getRadius());
	c.setPosition(this->pos.x, this->pos.y);

	window.draw(c);
}