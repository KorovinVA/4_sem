#include "collision.h"
#include <iostream>
constexpr auto X_SCREEN_SIZE = 640;
constexpr auto Y_SCREEN_SIZE = 480;

collision::collision() :
	topWall(false),
	bottomWall(false),
	rightWall(false),
	leftWall(false)
{}

void collision::checkWall(sf::Vector2f const pos)
{
	if (pos.y <= 0)
		topWall = true;
	else if (pos.y >= Y_SCREEN_SIZE)
		bottomWall = true;
	if (pos.x <= 0)
		leftWall = true;
	else if (pos.x >= X_SCREEN_SIZE)
		rightWall = true;
}


void collision::update(sf::Vector2f & velocity)
{
	if (topWall) 
	{
		topWall = false;
		velocity.y = -velocity.y;
	}
	else if (bottomWall)
	{
		bottomWall = false;
		velocity.y = -velocity.y;
	}
	if (rightWall)
	{
		rightWall = false;
		velocity.x = -velocity.x;
	}
	if (leftWall) 
	{
		leftWall = false;
		velocity.x = -velocity.x;
	}
}
