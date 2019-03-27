#include "Entity.h"

void Entity::setVelocity(sf::Vector2f velocity)
{
	Velocity_ = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	Velocity_.x = vx;
	Velocity_.y = vy;
}

sf::Vector2f Entity::getVelocity() const
{
	return Velocity_;
}
