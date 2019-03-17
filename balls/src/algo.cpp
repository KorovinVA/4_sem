#include "algo.h"

algo::algo() :
	window(sf::VideoMode(X_SCREEN_SIZE, Y_SCREEN_SIZE), "window")
{}

void algo::run()
{
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		processevents();
		update(dt);
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

void algo::update(sf::Time dt)
{
	for (int i = 0; i < NUMBERS_BALL; i++)
	{
		objects[i].checkWall(objects[i].getBall().getPosition());
		for (int j = NUMBERS_BALL - 1; j >= 0; j--) {
		if (i != j) {
				objects[i].collideBalls(
					objects[i].getBall().getPosition(), objects[j].getBall().getPosition(),
					objects[i].getMass(), objects[j].getMass(),
					objects[i].getVelocity(), objects[j].getVelocity(),
					objects[i].getRadius(), objects[j].getRadius()
				);
			}
		}
	}
	for (int i = 0; i < NUMBERS_BALL; i++) {
		objects[i].update(dt, i + 1);
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