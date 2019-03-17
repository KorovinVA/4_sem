#pragma once
#include "materialpoint.h"
#include "collision.h"

class ball : public materialpoint, public collision
{
private:
	float radius;
	sf::CircleShape orb;
public:
	ball();
	void update(sf::Time dt, int ball_number);
	sf::CircleShape getBall() const;
	float getRadius();
};