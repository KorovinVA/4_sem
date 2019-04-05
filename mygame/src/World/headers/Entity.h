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
	sf::Vector2f getVelocity() const;

public:
	bool isTurnedLeft();
	bool isTurnedRight();
private:
	virtual void updateCurrent(sf::Time dt);
private:
	sf::Vector2f Velocity_;

	bool Jumping;
	bool TurnedLeft;
	bool TurnedRight;
};