#pragma once

#include <SFML/Graphics.hpp>
#include "../../Resources/ResourceHolder.h"

class Animation {
protected:
	virtual void updateIdle();
	virtual void updateRun();
	virtual void updateAttack();
protected:
	sf::Sprite Sprite;

	std::pair<std::vector<sf::Texture>, size_t> Idle;
	std::pair<std::vector<sf::Texture>, size_t> Run;
	std::pair<std::vector<sf::Texture>, size_t> Attack;
private:
	sf::Clock idleTimeDelay;
	sf::Clock runTimeDelay;
	sf::Clock attackTimeDelay;

	size_t CurrentIdleText;
	size_t CurrentRunText;
	size_t CurrentAttackText;
};