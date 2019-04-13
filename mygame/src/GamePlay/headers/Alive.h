#pragma once

#include <SFML/Graphics.hpp>
#include "DataTables.h"

class Alive {
public:
	Alive();

	void makeConstants(const WarriorData * data);

	void attack();
	void die();
	bool isDealingDamage();
	void getDamage(int Damage);
protected:
	sf::Time fullAttackTime;
	sf::Time attackCooldown;
	sf::Clock CurrentAttackTime;

	sf::Time fullDieTime;
	sf::Clock CurrentDieTime;

	bool DealDamage;
	int RecievedDamage;
	bool dead;
};