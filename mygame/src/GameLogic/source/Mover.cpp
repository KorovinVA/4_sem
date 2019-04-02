#include "../headers/Mover.h"

Mover::Mover(float vx, float vy)
{
	Velocity.x = vx;
	Velocity.y = vy;
}

void Mover::operator()(SceneNode & node, sf::Time dt)
{}
