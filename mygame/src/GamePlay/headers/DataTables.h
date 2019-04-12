#pragma once
#include <algorithm>

#include "..\..\Resources\ResourceHolder.h"
#include "BoundsTables.h"

class WarriorData
{
public:
	WarriorData(int type_, TextureHolder * textures);
public:
	int hitpoints;
	int damage;
	float speed;
	std::vector<Textures::ID> idleTextPtr;
	std::vector<Textures::ID> runTextPtr;
	std::vector<Textures::ID> attackTextPtr;

	Bounds bounds;
private:
	void getTextures(size_t type);
};