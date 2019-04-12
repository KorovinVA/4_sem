#pragma once

#include <SFML/Graphics.hpp>
#include "../../Resources/ResourceHolder.h"

class Animation {
public:
	Animation(int type);
public:
	enum State
	{
		Idle,
		Run,
		Attack
	};

	enum Orientation
	{
		Left,
		Right
	};
protected:
	void createSpriteOrientation(Orientation orientation);
	void update(State state);
	bool isAttacking();
	void resetAttackValue();

	sf::Sprite Sprite;

	std::pair<std::vector<sf::Texture>, size_t> Idle_;
	std::pair<std::vector<sf::Texture>, size_t> Run_;
	std::pair<std::vector<sf::Texture>, size_t> Attack_;
private:
	virtual void updateIdle();
	virtual void updateRun();
	virtual void updateAttack();
private:
	sf::Clock idleTimeDelay;
	sf::Clock runTimeDelay;
	sf::Clock attackTimeDelay;

	float AttackFrequency;
	size_t AttackTextureNumber;
	bool NowAttacking;

	size_t CurrentIdleText;
	size_t CurrentRunText;
	size_t CurrentAttackText;
};