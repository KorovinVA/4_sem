#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "World.h"

class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	ResourceHolder<sf::Texture, int> textures;
	sf::RenderWindow Window;

	World world;
	bool IsPaused;
	
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;
};