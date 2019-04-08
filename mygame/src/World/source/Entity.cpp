#include "../headers/Entity.h"

Entity::Entity() :
Jumping(false),
TurnedRight(true),
TurnedLeft(false)
{
}

void Entity::setVelocity(sf::Vector2f velocity)
{
	Velocity_ = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	Velocity_.x = vx;
	Velocity_.y = vy;
}

void Entity::accelerate(sf::Vector2f velocity)
{
	if (velocity.x > 0) {
		TurnedRight = true;
		TurnedLeft = false;
	}
	else if (velocity.x < 0)
	{
		TurnedRight = false;
		TurnedLeft = true;
	}
	Velocity_ += velocity;
}

sf::Vector2f Entity::getVelocity() const
{
	return Velocity_;
}

bool Entity::isTurnedLeft() const
{
	return TurnedLeft;
}

bool Entity::isTurnedRight() const
{
	return TurnedRight;
}