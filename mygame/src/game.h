#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"

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

	sf::Clock idleTime;

private:
	ResourceHolder<sf::Texture, int> textures;
	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;

	

	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;
};