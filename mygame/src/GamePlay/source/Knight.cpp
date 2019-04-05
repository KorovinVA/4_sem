#include "../headers/Knight.h"
#include "../../Input/headers/Command.h"

constexpr float IDLE_FREQ = 0.1f;
constexpr float RUN_FREQ = 0.1f;
constexpr float ATTACK_FREQ = 0.1f;

Knight::Knight(TextureHolder * Textures)
{
	getTextures(Textures);
	Sprite.setTexture(Idle.front());
	sf::FloatRect bounds = Sprite.getLocalBounds();

	idleTimeDelay.restart();
	runTimeDelay.restart();
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

void Knight::update()
{
	sf::Vector2f CurrentSpeed = getVelocity();
	Sprite.move(CurrentSpeed);
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

void Knight::updateIdle()
{
	sf::Time timer = idleTimeDelay.getElapsedTime();
	if (timer.asSeconds() > IDLE_FREQ) {
		CurrentText = Idle.front();
		Sprite.setTexture(CurrentText);
		Idle.push(Idle.front());
		Idle.pop();
		idleTimeDelay.restart();
	}
}

void Knight::updateRun()
{
	sf::Time timer = runTimeDelay.getElapsedTime();
	if (timer.asSeconds() > RUN_FREQ) {
		CurrentText = Run.front();
		Sprite.setTexture(CurrentText);
		Run.push(Run.front());
		Run.pop();
		runTimeDelay.restart();
	}
}

void Knight::updateAttack()
{
	sf::Time timer = attackTimeDelay.getElapsedTime();
	if (timer.asSeconds() > ATTACK_FREQ) {
		CurrentText = Attack.front();
		Sprite.setTexture(CurrentText);
		Attack.push(Attack.front());
		Attack.pop();
		attackTimeDelay.restart();
	}
}

unsigned int Knight::getCategory()
{
	return Category::Knight;
}

void Knight::getIdleText(TextureHolder * Textures)
{
	Idle.push(Textures->get(Textures::Knight_Idle_1_000));
	Idle.push(Textures->get(Textures::Knight_Idle_1_001));
	Idle.push(Textures->get(Textures::Knight_Idle_1_002));
	Idle.push(Textures->get(Textures::Knight_Idle_1_003));
	Idle.push(Textures->get(Textures::Knight_Idle_1_004));
	Idle.push(Textures->get(Textures::Knight_Idle_1_005));
	Idle.push(Textures->get(Textures::Knight_Idle_1_006));
}

void Knight::getRunText(TextureHolder * Textures)
{
	Run.push(Textures->get(Textures::Knight_Run_1_000));
	Run.push(Textures->get(Textures::Knight_Run_1_001));
	Run.push(Textures->get(Textures::Knight_Run_1_002));
	Run.push(Textures->get(Textures::Knight_Run_1_003));
	Run.push(Textures->get(Textures::Knight_Run_1_004));
	Run.push(Textures->get(Textures::Knight_Run_1_005));
	Run.push(Textures->get(Textures::Knight_Run_1_006));
}

void Knight::getAttackText(TextureHolder * Textures)
{
	Attack.push(Textures->get(Textures::Knight_Attack_1_000));
	Attack.push(Textures->get(Textures::Knight_Attack_1_001));
	Attack.push(Textures->get(Textures::Knight_Attack_1_002));
	Attack.push(Textures->get(Textures::Knight_Attack_1_003));
	Attack.push(Textures->get(Textures::Knight_Attack_1_004));
	Attack.push(Textures->get(Textures::Knight_Attack_1_005));
	Attack.push(Textures->get(Textures::Knight_Attack_1_006));
	Attack.push(Textures->get(Textures::Knight_Attack_1_007));
}

void Knight::createSpriteOrientation()
{
	if (isTurnedLeft())
		Sprite.setTextureRect(sf::IntRect((int)Sprite.getLocalBounds().width, 0, (int)-Sprite.getLocalBounds().width,
			(int)Sprite.getLocalBounds().height));
	else if (isTurnedRight())
		Sprite.setTextureRect(sf::IntRect(Sprite.getLocalBounds()));
}
