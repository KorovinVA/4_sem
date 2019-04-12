#pragma once

#include <SFML/Graphics.hpp>
#include "../../Resources/ResourceHolder.h"
#include "..\headers\Assaulter.h"
#include "../headers/Warrior.h"

Assaulter::Assaulter(int type)
{
	switch (type)
	{
		case Warrior::Knight:
			fullAttackTime = sf::seconds(1.f);
			break;
		case Warrior::Golem:
			fullAttackTime = sf::seconds(1.3f);
			break;
	}
}

void Assaulter::attack()
{
	if (attackCooldown.asSeconds() == 0.f) {
		CurrentAttackTime.restart();
		attackCooldown = fullAttackTime;
	}
}
