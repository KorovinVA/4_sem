#include "algo.h"

algo::algo() :
	window(sf::VideoMode(640, 480), "window")
{}

void algo::run()
{
	while (window.isOpen())
	{
		processevents();
		update();
		render();
	}
}

void algo::processevents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		default:
			break;
		}
	}
}

void algo::update()
{
	for (int i = 0; i < NUMBERS_BALL; i++)
	{
		objects[i].update(0);
	}
}

void algo::render()
{
	window.clear(sf::Color::White);
	for (int i = 0; i < NUMBERS_BALL; i++)
	{
		window.draw(objects[i].getBall());
	}
	window.display();
}
