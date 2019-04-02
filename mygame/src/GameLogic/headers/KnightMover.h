#pragma once
#include <SFML/Graphics.hpp>
#include "../../World/headers/SceneNode.h"
#include "Mover.h"
#include "Knight.h"

class KnightMover : public Mover
{
public:
	KnightMover(float vx, float vy);
	virtual void operator() (SceneNode & node, sf::Time dt);
};