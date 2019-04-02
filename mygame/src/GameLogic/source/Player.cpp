#include "../headers/Player.h"

void Player::handlePlayerInput(const sf::Event, std::queue<Command> & Commands)
{}

void Player::handeRealTimeInput(std::queue<Command> & Commands)
{
	const float PLAYER_SPEED = 0.7f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Command moveRight;
		moveRight.category = Category::Knight;
		moveRight.action = KnightMover(PLAYER_SPEED, 0);
		Commands.push(moveRight);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Command moveLeft;
		moveLeft.category = Category::Knight;
		moveLeft.action = KnightMover(-PLAYER_SPEED, 0);
		Commands.push(moveLeft);
	}
}
