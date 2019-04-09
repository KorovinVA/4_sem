#pragma once
#include <functional>
#include <vector>
#include "..\..\Resources\ResourceHolder.h"

class WarriorData
{
public:
	int hitpoints;
	float speed;
	std::vector<Textures::ID> idleText;
	std::vector<Textures::ID> runText;
	std::vector<Textures::ID> attackText;
public:
	void getText(size_t type);
};

std::vector<WarriorData> initializeWarriorData();