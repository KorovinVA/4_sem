#pragma once
#include <SFML/Graphics.hpp>
#include "../../Resources/ResourceHolder.h"
#include "../../GameLogic/headers/Player.h"

struct Context
{
	Context(sf::RenderWindow& window,
		TextureHolder& textures,
		FontHolder& fonts,
		Player& player);
	sf::RenderWindow* window;
	TextureHolder* textures;
	FontHolder* fonts;
	Player* player;
};