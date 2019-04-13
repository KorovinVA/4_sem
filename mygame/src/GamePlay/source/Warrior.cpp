#include "../headers/Warrior.h"
#include "../../Input/headers/Command.h"
#include "../headers/DataTables.h"
#include "../headers/BarNode.h"
#include "../headers/BoundsTables.h"
#include "../headers/BarNode.h"
#include <iostream>

Warrior::Warrior(TextureHolder * Textures, Type type) :
	Animation(),
	Alive(),
	warriorType(type),
	Character(type, Textures),
	UniqueCommandIdentificator(rand() % 10000)
{
	Alive::makeConstants(&Character);
	Animation::getTextures(&Character, Textures);

	std::unique_ptr<BarNode> healthBar(new BarNode(BarNode::HealthBar, (float)Character.hitpoints));
	health = healthBar.get();
	attachChild(std::move(healthBar));
}

void Warrior::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(Sprite, states);
}

void Warrior::updateCurrent(sf::Time dt)
{
	if (dead)
	{
		Animation::update(Die);
		if (CurrentDieTime.getElapsedTime().asSeconds() >= fullDieTime.asSeconds())
		{
			// there must be delete call
		}
		return;
	}
	if(isTurnedLeft()) createSpriteOrientation(Left);
	else if(isTurnedRight()) createSpriteOrientation(Right);

	DealDamage = isAttacking();
	if (DealDamage) resetAttackValue();
	if (RecievedDamage != 0)
	{
		Character.hitpoints -= RecievedDamage;
		if (Character.hitpoints <= 0) die();
		RecievedDamage = 0;
		health->resizeBar((float)Character.hitpoints);
	}
	sf::Vector2f CurrentSpeed = getVelocity();
	if (attackCooldown != sf::Time::Zero) {
		sf::Time timer = CurrentAttackTime.getElapsedTime();
		if (attackCooldown.asSeconds() >= timer.asSeconds())
			Animation::update(Attack);
		else 
			attackCooldown = sf::Time::Zero;
	}
	else if(CurrentSpeed.x == 0.f && CurrentSpeed.y == 0.f) 
		Animation::update(Idle);
	else if (CurrentSpeed.y == 0.f) 
	{
		Animation::update(Run);
		move(CurrentSpeed * dt.asSeconds());
	}
}

int Warrior::getCategory()
{
	if(warriorType == Knight)
		return 1;
	return UniqueCommandIdentificator;
}

sf::Vector2f Warrior::getAttackArea()
{
	return Character.bounds.getAttackArea();
}

sf::Vector2f Warrior::getAttackPointOfReference()
{
	if (isTurnedLeft()) return Character.bounds.getAttackPointOfReference(Left);
	return Character.bounds.getAttackPointOfReference(Right);
}

int Warrior::getHitpoints()
{
	return Character.hitpoints;
}

int Warrior::getDamageValue()
{
	return Character.damage;
}