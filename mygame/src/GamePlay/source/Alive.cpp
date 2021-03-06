#pragma once

#include <SFML/Graphics.hpp>
#include "../../Resources/ResourceHolder.h"
#include "..\headers\Alive.h"
#include "../headers/Warrior.h"
#include <iostream>

Alive::Alive() :
	DealDamage(false),
	RecievedDamage(false),
	fullAttackTime(sf::Time::Zero),
	fullDieTime(sf::Time::Zero),
	dead(false),
	onGround(false),
	jumpCondition(0),
	falling(0)
{
}

void Alive::makeConstants(const WarriorData * data)
{
	fullAttackTime = data->fullAttackTime;
	fullDieTime = data->fullDieTime;
}

void Alive::attack()
{
	if (attackCooldown.asSeconds() == 0.f) {
		CurrentAttackTime.restart();
		attackCooldown = fullAttackTime;
	}
}

void Alive::die()
{
	CurrentDieTime.restart();
	dead = true;
}

bool Alive::isDealingDamage()
{
	return DealDamage;
}

void Alive::jump()
{
	if (isOnGround())
	{
		jumpCondition = 400.f;
		changeOnGround();
	}
}

bool Alive::isjumping()
{
	return false;
}

bool Alive::isOnGround()
{
	return onGround;
}

void Alive::changeOnGround()
{
	onGround = !onGround;
}

void Alive::getDamage(int Damage)
{
	RecievedDamage = Damage;
}

