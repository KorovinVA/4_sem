#include "..\headers\GameState.h"

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
