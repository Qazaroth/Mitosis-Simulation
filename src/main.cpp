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
	sf::RenderWindow window(sf::VideoMode(800, 800), title, styleFlag);
	window.setFramerateLimit(FRAMECAP);

	for (int i = 0; i < MAX_CELL_COUNT; i++)
	{
		Cell a(window);
		cells.push_back(a);
	}

	while (window.isOpen())
	{
		sf::Event windowEvent;

		window.clear(sf::Color(51, 51, 51, 255));
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

					for (int i = 0; i < cells.size(); i++)
					{
						if (cells[i].clicked(mousePos))
						{
							print("LOL");
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