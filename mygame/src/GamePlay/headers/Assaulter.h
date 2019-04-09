#pragma once

#include <SFML/Graphics.hpp>

class Assaulter {
public:
	void attack();
protected:
	sf::Time attackCooldown;
	sf::Clock attacking;
};