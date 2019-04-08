#include "..\headers\GameState.h"

GameState::GameState(StateStack & stack, Context context):
	State(stack, context),
	world(*context.window),
	player(*context.player)
{
}

bool GameState::update(sf::Time deltaTime)
{
	world.update(deltaTime);
	player.handeRealTimeInput(world.getCommandQueue());
	return true;
}

void GameState::draw()
{
	world.draw();
}

bool GameState::handleEvent(sf::Event & event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		requestStackPush(States::Pause);
	}
	return true;
}
