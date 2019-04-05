#pragma once

#include <SFML/Graphics.hpp>

class Assaulter {
public:
	virtual void attack();
protected:
	sf::Time attackCooldown;
	sf::Clock attacking;
};