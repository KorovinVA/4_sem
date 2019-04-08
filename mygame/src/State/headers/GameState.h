#pragma once
#include <SFML/Graphics.hpp>

#include "../../World/headers/World.h"
#include "../../Input/headers/Player.h"
#include "State.h"

class GameState : public State
{
public:
	GameState(StateStack& stack, Context context);

	virtual bool update(sf::Time deltaTime);
	virtual void draw();
	virtual bool handleEvent(sf::Event & event);

private:
	Player player;
	World world;
};