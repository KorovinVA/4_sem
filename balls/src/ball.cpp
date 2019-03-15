#include "ball.h"
#include "iostream"

constexpr auto RAD = 5;

ball::ball() :
	radius(RAD)
{
	orb.setRadius(radius);
	orb.setPosition(getStartPosition());
	orb.setFillColor(sf::Color::Black);
}

void ball::update(float dt)
{
	checkWall(orb.getPosition());
	collision::update(velocity);
	orb.move(getVelocity());
}

sf::CircleShape ball::getBall() const
{
	return orb;
}


