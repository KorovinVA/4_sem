#pragma once

#include <SFML/Graphics.hpp>
#include "../../Resources/ResourceHolder.h"
#include "..\headers\Assaulter.h"

void Assaulter::attack()
{
	if (attackCooldown.asSeconds() == 0.f) {
		attacking.restart();
		attackCooldown = sf::seconds(0.85f);
	}
}
