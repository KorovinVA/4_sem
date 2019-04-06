#pragma once
#include <SFML/Graphics.hpp>

#include "../../World/headers/World.h"
#include "../../Input/headers/Player.h"
#include "State.h"

class GameState : public State
{
public:
	GameState(StateStack& stack,
		Context context);

	virtual void update(sf::Time deltaTime);
	virtual void draw();

private:
	Player player;
	World world;
};