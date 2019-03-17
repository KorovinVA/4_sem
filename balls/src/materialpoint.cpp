#include "materialpoint.h"
#include <cstdlib>

constexpr auto WINDOW_X_SIZE = 640;
constexpr auto WINDOW_Y_SIZE = 480;

constexpr auto MAX_VELOCITY = 400;
constexpr auto MASS = 1;

materialpoint::materialpoint() :
	mass(MASS)
{
	startPosition.x = float(rand() % WINDOW_X_SIZE);
	startPosition.y = float(rand() % WINDOW_Y_SIZE);

	velocity.x = float(rand() % MAX_VELOCITY - MAX_VELOCITY/2);
	velocity.y = float(rand() % MAX_VELOCITY - MAX_VELOCITY/2);
}

sf::Vector2f materialpoint::getImpulse() const
{
	return sf::Vector2f(velocity * mass);
}

sf::Vector2f materialpoint::getVelocity() const
{
	return velocity;
}

sf::Vector2f materialpoint::getStartPosition() const
{
	return sf::Vector2f(startPosition);
}

float materialpoint::getMass()
{
	return mass;
}
