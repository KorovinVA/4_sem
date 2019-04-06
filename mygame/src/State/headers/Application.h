#pragma once
#include "StateStack.h"

class Application
{
public:
	Application();
	void run();
private:
	void registerStates();
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
private:
	StateStack mStateStack;
	TextureHolder textures;
	FontHolder fonts;
	sf::RenderWindow Window;
	Player player;
};