#include "ball.h"
#include <iostream>

constexpr auto RAD = 4;

ball::ball() :
	radius(RAD)
{
	orb.setRadius(radius);
	orb.setPosition(getStartPosition());
	orb.setFillColor(sf::Color::Black);
}

void ball::update(sf::Time dt, int ball_number)
{
	collision::update(velocity, ball_number);
	orb.move(getVelocity() * dt.asSeconds());
}

sf::CircleShape ball::getBall() const
{
	return orb;
}

float ball::getRadius()
{
	return radius;
}


