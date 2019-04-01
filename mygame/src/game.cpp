#include "game.h"
#include "ResourceHolder.h"

constexpr auto PLAYER_SPEED = 100;

Game::Game() : 
	Window(sf::VideoMode(1366, 768), "SFML Application", sf::Style::Fullscreen),
	mIsMovingDown(false),
	mIsMovingRight(false),
	mIsMovingLeft(false),
	mIsMovingUp(false),
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
		switch (event.type)
		{
		case sf::Event::GainedFocus:
			IsPaused = false;
			break;
		case sf::Event::LostFocus:
			IsPaused = true;
			break;
		case sf::Event::Closed:
			Window.close();
			break;
		case sf::Event::KeyPressed:
			if(event.key.code == sf::Keyboard::Escape)
				Window.close();
			break;
		}
	}
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

void Game::handlePlayerInput(sf::Keyboard::Key key,
	bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
	{
		mIsMovingLeft = isPressed;	}
	else if (key == sf::Keyboard::D)
	{
		mIsMovingRight = isPressed;
	}
	else if (key == sf::Keyboard::Escape)
	{
		Window.close();
	}
}