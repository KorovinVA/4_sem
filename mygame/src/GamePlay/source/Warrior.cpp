#include "../headers/Warrior.h"
#include "../../Input/headers/Command.h"
#include "../headers/DataTables.h"
#include "../headers/BarNode.h"

Warrior::Warrior(TextureHolder * Textures, Type type) :
	Animation(),
	warriorType(type)
{
	std::unique_ptr<BarNode> healthBar(new BarNode(sf::Color(200, 0, 30, 255)));
	healthBar->setPosition(0, -50);
	attachChild(std::move(healthBar));
	std::unique_ptr<BarNode> staminaBar(new BarNode(sf::Color(0, 199, 53, 255)));
	staminaBar->setPosition(0, -35);
	attachChild(std::move(staminaBar));
	getTextures(Textures);
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
	else return Category::Golem;
}

void Warrior::getIdleText(TextureHolder * Textures)
{
	int i = 0;
	for (auto p = Table[warriorType].idleText.begin(); p != Table[warriorType].idleText.end(); p++)
	{
		Idle_.first.push_back(Textures->get(Table[warriorType].idleText[i]));
		i++;
	}
	Idle_.second = Idle_.first.size();
}

void Warrior::getRunText(TextureHolder * Textures)
{
	int i = 0;
	for (auto p = Table[warriorType].runText.begin(); p != Table[warriorType].runText.end(); p++)
	{
		Run_.first.push_back(Textures->get(Table[warriorType].runText[i]));
		i++;
	}
	Run_.second = Run_.first.size();
}

void Warrior::getAttackText(TextureHolder * Textures)
{
	int i = 0;
	for (auto p = Table[warriorType].attackText.begin(); p != Table[warriorType].attackText.end(); p++)
	{
		Attack_.first.push_back(Textures->get(Table[warriorType].attackText[i]));
		i++;
	}
	Attack_.second = Attack_.first.size();
}
