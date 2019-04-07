#include "..\headers\GameState.h"

int i;

GameState::GameState(StateStack & stack, Context context):
	State(stack, context),
	world(*context.window),
	player(*context.player)
{
}

void GameState::update(sf::Time deltaTime)
{
	world.update(deltaTime);
	player.handeRealTimeInput(world.getCommandQueue());
}

void GameState::draw()
{
	world.draw();
}

void GameState::handleEvent(sf::Event & event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		requestStackPop();
		requestStackPush(States::Menu);
	}
}
