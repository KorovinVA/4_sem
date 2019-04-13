#pragma once

#include "../../World/headers/Entity.h"
#include "../../Resources/ResourceHolder.h"
#include "Animation.h"
#include "Alive.h"
#include "DataTables.h"
#include "BarNode.h"

class Warrior : public Entity, public Animation, public Alive
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
	int getCategory();

	sf::Vector2f getAttackArea();
	sf::Vector2f getAttackPointOfReference();

	int getHitpoints();
	int getDamageValue();
private:
	Type warriorType;
	WarriorData Character;
	BarNode * health;
	int UniqueCommandIdentificator;
};