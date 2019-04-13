#include "..\headers\Animation.h"
#include "..\headers\Warrior.h"

constexpr float IDLE_FREQ = 0.1f;
constexpr float RUN_FREQ = 0.1f;
constexpr float DIE_FREQ = 0.1f;

Animation::Animation():
	CurrentIdleText(0),
	CurrentRunText(0),
	CurrentAttackText(0),
	CurrentDieText(0),


	Idle_(0, 0),
	Run_(0, 0),
	Attack_(0, 0),
	Die_(0, 0),

	NowAttacking(false)
{
}

void Animation::getTextures(WarriorData * data, TextureHolder * textures)
{
	AttackFrequency = data->AttackFrequency;
	AttackTextureNumber = data->AttackTextureNumber;
	getIdleText(textures, data);
	getRunText(textures, data);
	getAttackText(textures, data);
	getDieText(textures, data);
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
		case Die:
			updateDie();
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
		if (CurrentAttackText == Attack_.second )
			CurrentAttackText = 0;
		Sprite.setTexture(Attack_.first.at(CurrentAttackText));
		attackTimeDelay.restart();
		if (CurrentAttackText == AttackTextureNumber)
			NowAttacking = true;
		++CurrentAttackText;
	}
}

void Animation::updateDie()
{
	sf::Time timer = dieTimeDelay.getElapsedTime();
	if (timer.asSeconds() > DIE_FREQ) {
		Sprite.setTexture(Die_.first.at(CurrentDieText));
		++CurrentDieText;
		if (CurrentDieText == Die_.second)
		{
			CurrentDieText = Die_.second - 1;
		}
		dieTimeDelay.restart();
	}
}

void Animation::getIdleText(TextureHolder * Textures, WarriorData * data)
{
	for (auto p = data->idleTextPtr.begin(); p != data->idleTextPtr.end(); p++)
	{
		Idle_.first.push_back(Textures->get(*p));
	}
	Idle_.second = Idle_.first.size();
}

void Animation::getRunText(TextureHolder * Textures, WarriorData * data)
{
	for (auto p = data->runTextPtr.begin(); p != data->runTextPtr.end(); p++)
	{
		Run_.first.push_back(Textures->get(*p));
	}
	Run_.second = Run_.first.size();
}

void Animation::getAttackText(TextureHolder * Textures, WarriorData * data)
{
	for (auto p = data->attackTextPtr.begin(); p != data->attackTextPtr.end(); p++)
	{
		Attack_.first.push_back(Textures->get(*p));
	}
	Attack_.second = Attack_.first.size();
}

void Animation::getDieText(TextureHolder * Textures, WarriorData * data)
{
	for (auto p = data->dieTextPtr.begin(); p != data->dieTextPtr.end(); p++)
	{
		Die_.first.push_back(Textures->get(*p));
	}
	Die_.second = Die_.first.size();
}
