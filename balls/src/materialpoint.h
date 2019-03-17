#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class materialpoint 
{
	float mass;
	sf::Vector2f startPosition;
protected:
	sf::Vector2f velocity;
public:
	materialpoint();
	sf::Vector2f getImpulse() const;
	sf::Vector2f getVelocity() const;
	sf::Vector2f getStartPosition() const;
	float getMass();
};