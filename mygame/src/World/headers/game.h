#pragma once
#include <SFML/Graphics.hpp>

#include "../../Resources/ResourceHolder.h"
#include "../headers/World.h"
#include "../../Input/headers/Player.h"

class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

private:
	TextureHolder textures;
	sf::RenderWindow Window;
	Player player;
	World world;
	bool IsPaused;
};