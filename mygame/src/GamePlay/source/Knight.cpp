#include "../headers/Knight.h"
#include "../../Input/headers/Command.h"

Knight::Knight(TextureHolder * Textures) :
	Animation()
{
	getTextures(Textures);
}

void Knight::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(Sprite, states);
}

void Knight::getTextures(TextureHolder * Textures)
{
	getIdleText(Textures);
	getRunText(Textures);
	getAttackText(Textures);
}

void Knight::updateCurrent(sf::Time dt)
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

unsigned int Knight::getCategory()
{
	return Category::Knight;
}

void Knight::getIdleText(TextureHolder * Textures)
{
	Idle_.first.push_back(Textures->get(Textures::Knight_Idle_1_000));
	Idle_.first.push_back(Textures->get(Textures::Knight_Idle_1_001));
	Idle_.first.push_back(Textures->get(Textures::Knight_Idle_1_002));
	Idle_.first.push_back(Textures->get(Textures::Knight_Idle_1_003));
	Idle_.first.push_back(Textures->get(Textures::Knight_Idle_1_004));
	Idle_.first.push_back(Textures->get(Textures::Knight_Idle_1_005));
	Idle_.first.push_back(Textures->get(Textures::Knight_Idle_1_006));
	Idle_.second = Idle_.first.size();
}

void Knight::getRunText(TextureHolder * Textures)
{
	Run_.first.push_back(Textures->get(Textures::Knight_Run_1_000));
	Run_.first.push_back(Textures->get(Textures::Knight_Run_1_001));
	Run_.first.push_back(Textures->get(Textures::Knight_Run_1_002));
	Run_.first.push_back(Textures->get(Textures::Knight_Run_1_003));
	Run_.first.push_back(Textures->get(Textures::Knight_Run_1_004));
	Run_.first.push_back(Textures->get(Textures::Knight_Run_1_005));
	Run_.first.push_back(Textures->get(Textures::Knight_Run_1_006));
	Run_.second = Run_.first.size();
}

void Knight::getAttackText(TextureHolder * Textures)
{
	Attack_.first.push_back(Textures->get(Textures::Knight_Attack_1_000));
	Attack_.first.push_back(Textures->get(Textures::Knight_Attack_1_001));
	Attack_.first.push_back(Textures->get(Textures::Knight_Attack_1_002));
	Attack_.first.push_back(Textures->get(Textures::Knight_Attack_1_003));
	Attack_.first.push_back(Textures->get(Textures::Knight_Attack_1_004));
	Attack_.first.push_back(Textures->get(Textures::Knight_Attack_1_005));
	Attack_.first.push_back(Textures->get(Textures::Knight_Attack_1_006));
	Attack_.first.push_back(Textures->get(Textures::Knight_Attack_1_007));
	Attack_.second = Attack_.first.size();
}
