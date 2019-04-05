#pragma once
#include <SFML/Graphics.hpp>
#include <queue>

#include "Command.h"
#include "Actions.h"

class Player
{
public:
	void handlePlayerInput(const sf::Event, std::queue<Command> & Commands);
	void handeRealTimeInput(std::queue<Command> & Commands);
};