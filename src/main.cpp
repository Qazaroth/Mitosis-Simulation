#include <iostream>
#include <SFML/Graphics.hpp>

#include "FPSTimer.h"
#include "Cell.h"

#define print(m) std::cout << m << std::endl

#define MAX_CELL_COUNT 2
#define FRAMECAP 60

std::string title = "Mitosis Simulation";
sf::Uint32 styleFlag = sf::Style::Default;

std::vector<Cell> cells;

FPSTimer timer;
float timerCounter = 0;
unsigned int frames = 0;

int main()
{
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(800, 800), title, styleFlag);
	window.setFramerateLimit(FRAMECAP);

	for (int i = 0; i < MAX_CELL_COUNT; i++)
	{
		sf::Vector2u size = window.getSize();

		unsigned int width = size.x;
		unsigned int height = size.y;

		int r = randomFloat(100, 255);
		int b = randomFloat(100, 255);

		int x = randomInt(0, width);
		int y = randomInt(0, height);

		sf::Color c(r, 0, b, 100);

		Cell a(sf::Vector2f(x, y), 60.0f, c);
		cells.push_back(a);
	}

	while (window.isOpen())
	{
		sf::Event windowEvent;

		window.clear(sf::Color(200, 200, 200, 255));
		for (int i = 0; i < cells.size(); i++)
		{
			cells[i].move();
			cells[i].show(window);
		}
		window.display();

		while (window.pollEvent(windowEvent))
		{
			switch (windowEvent.type)
			{
			case sf::Event::MouseButtonPressed:
			{
				auto btnCode = sf::Mouse::Button::Left;

				if (windowEvent.mouseButton.button == btnCode)
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);

					for (int i = cells.size(); i >= 0; i--)
					{
						if (cells[i].clicked(mousePos))
						{
							cells.push_back(cells[i].mitosis());
							cells.push_back(cells[i].mitosis());
							cells.erase(std::next(cells.begin(), i));
						}
					}
				}
				break;
			}
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		frames++;
		if (timer.elapsed() - timerCounter > 1.0f)
		{
			timerCounter += 1.0f;
			printf("%d FPS\n", frames);
			frames = 0;
		}
	}

	return 0;
}