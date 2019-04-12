#pragma once

#include <SFML/Graphics.hpp>
#include "DataTables.h"

class Alive {
public:
	Alive();

	void makeConstants(const WarriorData * data);

	void attack();
	bool isDealingDamage();
	void getDamage(int Damage);
protected:
	sf::Time fullAttackTime;
	sf::Time attackCooldown;
	sf::Clock CurrentAttackTime;

	bool DealDamage;
	int RecievedDamage;
};