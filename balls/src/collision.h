#pragma once
#include <SFML/Graphics.hpp>

class collision 
{
private:
	bool topWall;
	bool bottomWall;
	bool rightWall;
	bool leftWall;
public:
	collision();
	void checkWall(sf::Vector2f const pos);
	void update(sf::Vector2f & velocity);
};