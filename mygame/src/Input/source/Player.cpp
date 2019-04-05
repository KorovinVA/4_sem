#include "../headers/Player.h"

void Player::handlePlayerInput(const sf::Event, std::queue<Command> & Commands)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Command attack;
		attack.category = Category::Knight;
		attack.action = Attack<Knight>();
		Commands.push(attack);
	}
}

void Player::handeRealTimeInput(std::queue<Command> & Commands)
{
	const float PLAYER_SPEED = 0.7f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Command moveRight;
		moveRight.category = Category::Knight;
		moveRight.action = Move<Knight>(PLAYER_SPEED, 0);
		Commands.push(moveRight);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Command moveLeft;
		moveLeft.category = Category::Knight;
		moveLeft.action = Move<Knight>(-PLAYER_SPEED, 0);
		Commands.push(moveLeft);
	}
}
