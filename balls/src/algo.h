#pragma once
#include "ball.h"
#include <SFML/Graphics.hpp>

constexpr auto NUMBERS_BALL = 30;

class algo
{
private:
	sf::RenderWindow window;
	ball objects[NUMBERS_BALL];

	void processevents();
	void update();
	void render();
public:
	algo();
	void run();
};
