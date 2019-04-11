#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Bounds
{
public:
	Bounds(int type_, TextureHolder * textures);
public:
	sf::Vector2f getAttackArea();
	sf::Vector2f getAttackPointOfReference(Animation::Orientation type);
private:
	sf::Vector2f LeftAttackPointOfReference;
	sf::Vector2f RightAttackPointOfReference;
	sf::Vector2f AttackArea;
};