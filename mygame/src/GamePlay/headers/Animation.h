#pragma once

#include <SFML/Graphics.hpp>
#include "../../Resources/ResourceHolder.h"

class Animation {
public:
	Animation();
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
public:
	void createSpriteOrientation(Orientation orientation);
	void update(State state);
protected:
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

	size_t CurrentIdleText;
	size_t CurrentRunText;
	size_t CurrentAttackText;
};