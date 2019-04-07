#pragma once
#include <SFML/Graphics.hpp>
#include "../../Resources/ResourceHolder.h"
#include "../../Input/headers/Player.h"

struct Context
{
	Context(sf::RenderWindow& window_,
		TextureHolder& textures_,
		FontHolder& fonts_,
		Player& player_);
	sf::RenderWindow* window;
	TextureHolder* textures;
	FontHolder* fonts;
	Player* player;
};