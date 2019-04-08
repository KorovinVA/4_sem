#include "..\headers\Golem.h"

Golem::Golem(TextureHolder * Textures) :
	Animation()
{
	getTextures(Textures);
}

void Golem::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(Sprite, states);
}

void Golem::updateCurrent(sf::Time dt)
{
	sf::Vector2f CurrentSpeed = getVelocity();

	if (isTurnedLeft()) createSpriteOrientation(Left);
	else if (isTurnedRight()) createSpriteOrientation(Right);

	if (attackCooldown != sf::Time::Zero) {
		sf::Time timer = attacking.getElapsedTime();
		if (attackCooldown.asSeconds() >= timer.asSeconds())
			Animation::update(Attack);
		else
			attackCooldown = sf::Time::Zero;
	}
	else if (CurrentSpeed.x == 0.f && CurrentSpeed.y == 0.f)
		Animation::update(Idle);
	else if (CurrentSpeed.y == 0.f)
	{
		Animation::update(Run);
		move(CurrentSpeed * dt.asSeconds());
	}
}

unsigned int Golem::getCategory()
{
	return Category::Golem;
}

void Golem::getTextures(TextureHolder * Textures)
{
	getIdleText(Textures);
	getRunText(Textures);
	getAttackText(Textures);
}

void Golem::getIdleText(TextureHolder * Textures)
{
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_000));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_001));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_002));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_003));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_004));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_005));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_006));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_007));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_008));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_009));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_010));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_011));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_012));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_013));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_014));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_015));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_016));
	Idle_.first.push_back(Textures->get(Textures::Golem_Idle_1_017));
	Idle_.second = Idle_.first.size();
}

void Golem::getRunText(TextureHolder * Textures)
{
}

void Golem::getAttackText(TextureHolder * Textures)
{
}
