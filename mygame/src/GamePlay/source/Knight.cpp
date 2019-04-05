#include "../headers/Knight.h"
#include "../../Input/headers/Command.h"

constexpr float IDLE_FREQ = 0.1f;
constexpr float RUN_FREQ = 0.1f;
constexpr float ATTACK_FREQ = 0.1f;

Knight::Knight(TextureHolder * Textures)
{
	getTextures(Textures);
	Sprite.setTexture(*Idle.first.begin());
	sf::FloatRect bounds = Sprite.getLocalBounds();
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

void Knight::update(sf::Time dt)
{
	sf::Vector2f CurrentSpeed = getVelocity();
	move(CurrentSpeed * dt.asSeconds());
	createSpriteOrientation();
	if (attackCooldown != sf::Time::Zero) {
		sf::Time timer = attacking.getElapsedTime();
		if (attackCooldown.asSeconds() >= timer.asSeconds())
			updateAttack();
		else 
			attackCooldown = sf::Time::Zero;
	}
	else if(CurrentSpeed.x == 0.f && CurrentSpeed.y == 0.f) updateIdle();
	else if (CurrentSpeed.y == 0.f) updateRun();
}

unsigned int Knight::getCategory()
{
	return Category::Knight;
}

void Knight::getIdleText(TextureHolder * Textures)
{
	Idle.first.push_back(Textures->get(Textures::Knight_Idle_1_000));
	Idle.first.push_back(Textures->get(Textures::Knight_Idle_1_001));
	Idle.first.push_back(Textures->get(Textures::Knight_Idle_1_002));
	Idle.first.push_back(Textures->get(Textures::Knight_Idle_1_003));
	Idle.first.push_back(Textures->get(Textures::Knight_Idle_1_004));
	Idle.first.push_back(Textures->get(Textures::Knight_Idle_1_005));
	Idle.first.push_back(Textures->get(Textures::Knight_Idle_1_006));
	Idle.second = Idle.first.size();
}

void Knight::getRunText(TextureHolder * Textures)
{
	Run.first.push_back(Textures->get(Textures::Knight_Run_1_000));
	Run.first.push_back(Textures->get(Textures::Knight_Run_1_001));
	Run.first.push_back(Textures->get(Textures::Knight_Run_1_002));
	Run.first.push_back(Textures->get(Textures::Knight_Run_1_003));
	Run.first.push_back(Textures->get(Textures::Knight_Run_1_004));
	Run.first.push_back(Textures->get(Textures::Knight_Run_1_005));
	Run.first.push_back(Textures->get(Textures::Knight_Run_1_006));
	Run.second = Run.first.size();
}

void Knight::getAttackText(TextureHolder * Textures)
{
	Attack.first.push_back(Textures->get(Textures::Knight_Attack_1_000));
	Attack.first.push_back(Textures->get(Textures::Knight_Attack_1_001));
	Attack.first.push_back(Textures->get(Textures::Knight_Attack_1_002));
	Attack.first.push_back(Textures->get(Textures::Knight_Attack_1_003));
	Attack.first.push_back(Textures->get(Textures::Knight_Attack_1_004));
	Attack.first.push_back(Textures->get(Textures::Knight_Attack_1_005));
	Attack.first.push_back(Textures->get(Textures::Knight_Attack_1_006));
	Attack.first.push_back(Textures->get(Textures::Knight_Attack_1_007));
	Attack.second = Attack.first.size();
}

void Knight::createSpriteOrientation()
{
	if (isTurnedLeft())
		Sprite.setTextureRect(sf::IntRect((int)Sprite.getLocalBounds().width, 0, (int)-Sprite.getLocalBounds().width,
			(int)Sprite.getLocalBounds().height));
	else if (isTurnedRight())
		Sprite.setTextureRect(sf::IntRect(Sprite.getLocalBounds()));
}
