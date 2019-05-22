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
	if (isTurnedLeft()) createSpriteOrientation(Left);
	else if (isTurnedRight()) createSpriteOrientation(Right);

	if (dead)
	{
		updateDying();
		return ;
	}

	DealDamage = isAttacking();
	if (DealDamage) resetAttackValue();
	if (RecievedDamage != 0) updateGettingDamage();

	sf::Vector2f CurrentSpeed = getVelocity();
	if (attackCooldown != sf::Time::Zero) updateAttack();
	else if(CurrentSpeed.x == 0.f && CurrentSpeed.y == 0.f) 
		Animation::update(Idle);
	else if (CurrentSpeed.y == 0.f) 
	{
		Animation::update(Run);
		move(CurrentSpeed * dt.asSeconds());
	}
	if(jumpCondition)
	{
		if (isOnGround())
		{
			falling -= 981 * dt.asSeconds();
			jumpCondition = 0;
			return;
		}
		move(0, -jumpCondition * dt.asSeconds());
		jumpCondition -= 981 * dt.asSeconds();
	}
	else
	{
		if (isOnGround() == false)
		{
			falling -= 10 * dt.asSeconds();
			move(0, -falling);
		}
		if (isOnGround() == true)
		{
			falling = 0;
		}
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

void Warrior::updateDying()
{
	Animation::update(Die);
	if (CurrentDieTime.getElapsedTime().asSeconds() >= fullDieTime.asSeconds())
	{
		// there must be delete call
	}
	return;
}

void Warrior::updateGettingDamage()
{
	Character.hitpoints -= RecievedDamage;
	if (Character.hitpoints <= 0) die();
	RecievedDamage = 0;
	health->resizeBar((float)Character.hitpoints);
}

void Warrior::updateAttack()
{
	sf::Time timer = CurrentAttackTime.getElapsedTime();
	if (attackCooldown.asSeconds() >= timer.asSeconds())
		Animation::update(Attack);
	else
		attackCooldown = sf::Time::Zero;
}
