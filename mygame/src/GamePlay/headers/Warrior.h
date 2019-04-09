#pragma once

#include "../../World/headers/Entity.h"
#include "../../Resources/ResourceHolder.h"
#include "Animation.h"
#include "Assaulter.h"
#include "DataTables.h"

class Warrior : public Entity, public Animation, public Assaulter
{
public:
	enum Type
	{
		Knight,
		Golem,
		TypeCount
	};
public:
	Warrior(TextureHolder * Textures, Type type);

	void drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const;
	void updateCurrent(sf::Time dt) override;
	unsigned int getCategory();
private:
	void getTextures(TextureHolder * Textures);
	void getIdleText(TextureHolder * Textures);
	void getRunText(TextureHolder * Textures);
	void getAttackText(TextureHolder * Textures);
private:
	std::vector<WarriorData> Table = initializeWarriorData();
	Type warriorType;
};