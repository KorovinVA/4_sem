#pragma once
#include "..\headers\BoundsTables.h"
#include "..\headers\Warrior.h"

Bounds::Bounds(int type_, TextureHolder * textures)
{
	sf::Texture temp;
	sf::Vector2u size;
	switch(type_)
	{
		case Warrior::Knight:
			temp = textures->get(Textures::Knight_Idle_1_000);
			size = temp.getSize();
			RightAttackPointOfReference.x = (float)size.x / 3;
			RightAttackPointOfReference.y = (float)size.y;

			LeftAttackPointOfReference.x = (float)size.x * 2 / 3;
			LeftAttackPointOfReference.y = (float)size.y;

			AttackArea.x = (float)size.x * 2 / 3;
			AttackArea.y = (float)size.y / 2;
		break;
		case Warrior::Golem:
			temp = textures->get(Textures::Golem_Idle_1_000);
			size = temp.getSize();

			RightAttackPointOfReference.x = (float)size.x / 2;
			RightAttackPointOfReference.y = (float)size.y;

			LeftAttackPointOfReference.x = (float)size.x / 2;
			LeftAttackPointOfReference.y = (float)size.y;

			AttackArea.x = (float)size.x / 2;
			AttackArea.y = (float)size.y / 3;
		break;
	}
}

sf::Vector2f Bounds::getAttackArea()
{
	return AttackArea;
}

sf::Vector2f Bounds::getAttackPointOfReference(int type)
{
	switch (type)
	{
	case Animation::Right:
		return RightAttackPointOfReference;
	case Animation::Left:
		return LeftAttackPointOfReference;
	}
	return sf::Vector2f(0, 0);
}
