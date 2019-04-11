#include "../headers/Warrior.h"
#include "../../Input/headers/Command.h"
#include "../headers/DataTables.h"
#include "../headers/BarNode.h"
#include "../headers/BoundsTables.h"

Warrior::Warrior(TextureHolder * Textures, Type type) :
	Animation(),
	warriorType(type),
	Character(type, Textures)
{
	/*std::unique_ptr<BarNode> healthBar(new BarNode(sf::Color(200, 0, 30, 255)));
	healthBar->setPosition(0, -50);
	attachChild(std::move(healthBar));
	std::unique_ptr<BarNode> staminaBar(new BarNode(sf::Color(0, 199, 53, 255)));
	staminaBar->setPosition(0, -35);
	attachChild(std::move(staminaBar));*/

	getTextures(Textures);
	Sprite.setTexture(Idle_.first.at(0));
}

void Warrior::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(Sprite, states);
}

void Warrior::getTextures(TextureHolder * Textures)
{
	getIdleText(Textures);
	getRunText(Textures);
	getAttackText(Textures);
}

void Warrior::updateCurrent(sf::Time dt)
{
	sf::Vector2f CurrentSpeed = getVelocity();

	if(isTurnedLeft()) createSpriteOrientation(Left);
	else if(isTurnedRight()) createSpriteOrientation(Right);

	if (attackCooldown != sf::Time::Zero) {
		sf::Time timer = attacking.getElapsedTime();
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

unsigned int Warrior::getCategory()
{
	if(warriorType == Knight)
		return Category::Warrior;
	return Category::Golem;
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

void Warrior::getIdleText(TextureHolder * Textures)
{
	int i = 0;
	for (auto p = Character.idleTextPtr.begin(); p != Character.idleTextPtr.end(); p++)
	{
		Idle_.first.push_back(Textures->get(Character.idleTextPtr[i]));
		i++;
	}
	Idle_.second = Idle_.first.size();
}

void Warrior::getRunText(TextureHolder * Textures)
{
	int i = 0;
	for (auto p = Character.runTextPtr.begin(); p != Character.runTextPtr.end(); p++)
	{
		Run_.first.push_back(Textures->get(Character.runTextPtr[i]));
		i++;
	}
	Run_.second = Run_.first.size();
}

void Warrior::getAttackText(TextureHolder * Textures)
{
	int i = 0;
	for (auto p = Character.attackTextPtr.begin(); p != Character.attackTextPtr.end(); p++)
	{
		Attack_.first.push_back(Textures->get(Character.attackTextPtr[i]));
		i++;
	}
	Attack_.second = Attack_.first.size();
}
