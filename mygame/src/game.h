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
	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;
	sf::Clock idleTime;

	World world;
	

	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;
};