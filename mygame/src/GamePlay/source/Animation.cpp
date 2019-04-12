#include "..\headers\Animation.h"
#include "..\headers\Warrior.h"

constexpr float IDLE_FREQ = 0.1f;
constexpr float RUN_FREQ = 0.1f;

Animation::Animation():
	 CurrentIdleText(0),
	 CurrentRunText(0),
	 CurrentAttackText(0),

	Idle_(0, 0),
	Run_(0, 0),
	Attack_(0, 0),

	NowAttacking(false)
{
}

void Animation::makeConstants(WarriorData * data)
{
	AttackFrequency = data->AttackFrequency;
	AttackTextureNumber = data->AttackTextureNumber;
}

void Animation::createSpriteOrientation(Orientation orientation)
{
	switch (orientation)
	{
		case Left:
			Sprite.setTextureRect(sf::IntRect((int)Sprite.getLocalBounds().width, 0, (int)-Sprite.getLocalBounds().width,
				(int)Sprite.getLocalBounds().height));
			break;
		case Right:
			Sprite.setTextureRect(sf::IntRect(Sprite.getLocalBounds()));
			break;
	}
}

void Animation::update(State state)
{
	switch (state)
	{
		case Idle:
			updateIdle();
			break;
		case Run:
			updateRun();
			break;
		case Attack:
			updateAttack();
			break;
	}
}

bool Animation::isAttacking()
{
	return NowAttacking;
}

void Animation::resetAttackValue()
{
	NowAttacking = false;
}

void Animation::updateIdle()
{
	sf::Time timer = idleTimeDelay.getElapsedTime();
	if (timer.asSeconds() > IDLE_FREQ) {
		if (CurrentIdleText == Idle_.second)
			CurrentIdleText = 0;
		CurrentAttackText = 0;
		Sprite.setTexture(Idle_.first.at(CurrentIdleText));
		++CurrentIdleText;
		idleTimeDelay.restart();
	}
}

void Animation::updateRun()
{
	sf::Time timer = runTimeDelay.getElapsedTime();
	if (timer.asSeconds() > RUN_FREQ) {
		if (CurrentRunText == Run_.second)
			CurrentRunText = 0;
		CurrentAttackText = 0;
		Sprite.setTexture(Run_.first.at(CurrentRunText));
		++CurrentRunText;
		runTimeDelay.restart();
	}
}

void Animation::updateAttack()
{
	sf::Time timer = attackTimeDelay.getElapsedTime();
	if (timer.asSeconds() > AttackFrequency) {
		if (CurrentAttackText == Attack_.second)
			CurrentAttackText = 0;
		Sprite.setTexture(Attack_.first.at(CurrentAttackText));
		attackTimeDelay.restart();
		if (CurrentAttackText == AttackTextureNumber)
			NowAttacking = true;
		++CurrentAttackText;
	}
}
