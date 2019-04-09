#include "../headers/Player.h"

void Player::handlePlayerInput(const sf::Event, std::queue<Command> & Commands)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Command attack;
		attack.category = Category::Warrior;
		attack.action = Attack<Warrior>();
		Commands.push(attack);
	}
}

void Player::handeRealTimeInput(std::queue<Command> & Commands)
{
	const float PLAYER_SPEED = 300.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Command moveRight;
		moveRight.category = Category::Warrior;
		moveRight.action = Move<Warrior>(PLAYER_SPEED, 0);
		Commands.push(moveRight);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Command moveLeft;
		moveLeft.category = Category::Warrior;
		moveLeft.action = Move<Warrior>(-PLAYER_SPEED, 0);
		Commands.push(moveLeft);
	}
}
