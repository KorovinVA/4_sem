#pragma once

#include <SFML/Graphics.hpp>
#include "../../Resources/ResourceHolder.h"
#include "..\headers\Alive.h"
#include "../headers/Warrior.h"

Alive::Alive() :
	DealDamage(false),
	RecievedDamage(false),
	fullAttackTime(sf::Time::Zero)
{
}

void Alive::makeConstants(const WarriorData * data)
{
	fullAttackTime = data->fullAttackTime;
}

void Alive::attack()
{
	if (attackCooldown.asSeconds() == 0.f) {
		CurrentAttackTime.restart();
		attackCooldown = fullAttackTime;
	}
}

bool Alive::isDealingDamage()
{
	return DealDamage;
}

void Alive::getDamage(int Damage)
{
	RecievedDamage = Damage;
}

