#include "game.h"
#include "ResourceHolder.h"

constexpr auto PLAYER_SPEED = 100;

Game::Game() : 
	mWindow(sf::VideoMode(640, 480), "SFML Application"),	mPlayer(),
	mIsMovingDown(false),
	mIsMovingRight(false),
	mIsMovingLeft(false),
	mIsMovingUp(false),
	world(mWindow)
{
	mPlayer.setScale(0.25, 0.25);
	mPlayer.setPosition(100.f, 100.f);
}

void Game::run()
{
	sf::Clock clock;
	while (mWindow.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		processEvents();
		update(deltaTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= PLAYER_SPEED;
	if (mIsMovingDown)
		movement.y += PLAYER_SPEED;
	if (mIsMovingLeft)
		movement.x -= PLAYER_SPEED;
	if (mIsMovingRight)
		movement.x += PLAYER_SPEED;
	world.update(deltaTime);
}

void Game::render()
{

	mWindow.clear();
	world.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.display();
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
		mIsMovingLeft = isPressed;
		//mPlayer.setTexture(textures.get(Textures::Hero_Idle_000_Left));
	}
	else if (key == sf::Keyboard::D)
	{
		mIsMovingRight = isPressed;
		//mPlayer.setTexture(textures.get(Textures::Hero_Right));
	}
}