#include "..\headers\Animation.h"

constexpr float IDLE_FREQ = 0.1f;
constexpr float RUN_FREQ = 0.1f;
constexpr float ATTACK_FREQ = 0.1f;

void Animation::updateIdle()
{
	sf::Time timer = idleTimeDelay.getElapsedTime();
	if (timer.asSeconds() > IDLE_FREQ) {
		if (CurrentIdleText == Idle.second)
			CurrentIdleText = 0;
		Sprite.setTexture(Idle.first.at(CurrentIdleText));
		++CurrentIdleText;
		idleTimeDelay.restart();
	}
}

void Animation::updateRun()
{
	sf::Time timer = runTimeDelay.getElapsedTime();
	if (timer.asSeconds() > RUN_FREQ) {
		if (CurrentRunText == Run.second)
			CurrentRunText = 0;
		Sprite.setTexture(Run.first.at(CurrentRunText));
		++CurrentRunText;
		runTimeDelay.restart();
	}
}

void Animation::updateAttack()
{
	sf::Time timer = attackTimeDelay.getElapsedTime();
	if (timer.asSeconds() > ATTACK_FREQ) {
		if (CurrentAttackText == Attack.second)
			CurrentAttackText = 0;
		Sprite.setTexture(Attack.first.at(CurrentAttackText));
		++CurrentAttackText;
		attackTimeDelay.restart();
	}
}
