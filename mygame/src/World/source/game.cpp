#include "../headers/game.h"
#include "../../Resources/ResourceHolder.h"

constexpr auto PLAYER_SPEED = 100;

Game::Game() : 
	Window(sf::VideoMode(1366, 768), "SFML Application", sf::Style::Fullscreen),
	world(Window)
{}

void Game::run()
{
	sf::Clock clock;
	while (Window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		if(!IsPaused) update(deltaTime);
		render();
		processEvents();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (Window.pollEvent(event))
	{
		player.handlePlayerInput(event, world.getCommandQueue());
		if (event.type == sf::Event::Closed)
		{
			Window.close();
		}
	}
	player.handeRealTimeInput(world.getCommandQueue());
}

void Game::update(sf::Time deltaTime)
{
	world.update(deltaTime);
}

void Game::render()
{
	Window.clear();
	world.draw();
	//mWindow.setView(mWindow.getDefaultView());
	Window.display();
}