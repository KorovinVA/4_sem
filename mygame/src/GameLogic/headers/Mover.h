#pragma once
#include <SFML/Graphics.hpp>
#include "../../World/headers/SceneNode.h"

class Mover {
protected:
	Mover(float vx, float vy);
	virtual void operator() (SceneNode & node, sf::Time dt);
protected:
	sf::Vector2f Velocity;
};