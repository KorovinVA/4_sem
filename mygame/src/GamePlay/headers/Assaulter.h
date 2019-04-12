#pragma once

#include <SFML/Graphics.hpp>

class Assaulter {
public:
	Assaulter(int type);
public:
	void attack();
protected:
	sf::Time fullAttackTime;
	sf::Time attackCooldown;
	sf::Clock CurrentAttackTime;
};