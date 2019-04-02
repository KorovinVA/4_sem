#include "..\headers\KnightMover.h"

KnightMover::KnightMover(float vx, float vy) :
	Mover(vx, vy)
{}

void KnightMover::operator()(SceneNode & node, sf::Time dt)
{
	Knight & knight = static_cast<Knight&>(node);
	knight.accelerate(Velocity);
}
