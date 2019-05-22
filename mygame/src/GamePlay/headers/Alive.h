#pragma once

#include <SFML/Graphics.hpp>
#include "DataTables.h"
#include "../../World/headers/Entity.h"

class Alive : public Entity
{
public:
	Alive();

	void makeConstants(const WarriorData * data);

	void die();
	void getDamage(int Damage);

	void attack();
	bool isDealingDamage();

	void jump();
	bool isjumping();
	bool isOnGround();
	void changeOnGround();
protected:
	sf::Time fullAttackTime;
	sf::Time attackCooldown;
	sf::Clock CurrentAttackTime;

	sf::Time fullDieTime;
	sf::Clock CurrentDieTime;

	bool DealDamage;
	int RecievedDamage;
	bool dead;

	float jumpCondition;
	float falling;
	float onGround;
};