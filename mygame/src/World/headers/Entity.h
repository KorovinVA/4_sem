#pragma once
#include <SFML/Graphics.hpp>
#include "../headers/SceneNode.h"

class Entity : public SceneNode
{
public:
	Entity();
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	void accelerate(sf::Vector2f velocity);

	void reTurn();
	sf::Vector2f getVelocity() const;
	bool isTurnedLeft() const;
	bool isTurnedRight() const;

private:
	sf::Vector2f Velocity_;

	bool Jumping;
	bool TurnedLeft;
	bool TurnedRight;

	int Hitpoints;
};