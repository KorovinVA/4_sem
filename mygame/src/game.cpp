#include "game.h"
#include "ResourceHolder.h"

constexpr auto PLAYER_SPEED = 100;

Game::Game() : 
	mWindow(sf::VideoMode(640, 480), "SFML Application"), 	mPlayer(),
	mIsMovingDown(false),
	mIsMovingRight(false),
	mIsMovingLeft(false),
	mIsMovingUp(false),
	idleTime()
{

	//textures.load(Textures::Hero_Right, "../media/textures/2d_knight_idle_right.png");
	textures.load(Textures::Hero_Idle_000_Left, "../media/textures/2D_KNIGHT__Idle_000.png");
	textures.load(Textures::Hero_Idle_001_Left, "../media/textures/2D_KNIGHT__Idle_001.png");
	textures.load(Textures::Hero_Idle_002_Left, "../media/textures/2D_KNIGHT__Idle_002.png");
	textures.load(Textures::Hero_Idle_003_Left, "../media/textures/2D_KNIGHT__Idle_003.png");
	textures.load(Textures::Hero_Idle_004_Left, "../media/textures/2D_KNIGHT__Idle_004.png");
	textures.load(Textures::Hero_Idle_005_Left, "../media/textures/2D_KNIGHT__Idle_005.png");
	textures.load(Textures::Hero_Idle_006_Left, "../media/textures/2D_KNIGHT__Idle_006.png");
	textures.load(Textures::Hero_Idle_007_Left, "../media/textures/2D_KNIGHT__Idle_007.png");

	mPlayer.setTexture(textures.get(Textures::Hero_Idle_000_Left));
	mPlayer.setScale(0.25, 0.25);
	mPlayer.setPosition(100.f, 100.f);
	
	idleTime.restart();
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

	sf::Time timer = idleTime.getElapsedTime();
	float k = timer.asSeconds();
	if(k >= 0.1f && k < 0.2f) {
		mPlayer.setTexture(textures.get(Textures::Hero_Idle_001_Left));
	}
	else if (k >= 0.2f && k < 0.3f) {
		mPlayer.setTexture(textures.get(Textures::Hero_Idle_002_Left));
	}
	else if (k >= 0.3f && k < 0.4f) {
		mPlayer.setTexture(textures.get(Textures::Hero_Idle_003_Left));
	}
	else if (k >= 0.4f && k < 0.5f) {
		mPlayer.setTexture(textures.get(Textures::Hero_Idle_004_Left));
	}
	else if (k >= 0.5f && k < 0.6f) {
		mPlayer.setTexture(textures.get(Textures::Hero_Idle_005_Left));
	}
	else if (k >= 0.6f && k < 0.7f) {
		mPlayer.setTexture(textures.get(Textures::Hero_Idle_006_Left));
	}
	else if (k >= 0.7f && k < 0.8f) {
		mPlayer.setTexture(textures.get(Textures::Hero_Idle_007_Left));
	}
	else if (k >= 0.8) {
		idleTime.restart();
		mPlayer.setTexture(textures.get(Textures::Hero_Idle_000_Left));
	}

	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{

	mWindow.clear();
	mWindow.draw(mPlayer);
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
		mPlayer.setTexture(textures.get(Textures::Hero_Idle_000_Left));
	}
	else if (key == sf::Keyboard::D)
	{
		mIsMovingRight = isPressed;
		//mPlayer.setTexture(textures.get(Textures::Hero_Right));
	}
}