#include "collision.h"
#include "mathfunctions.h"
#include <iostream>

collision::collision() :
	topWall(false),
	bottomWall(false),
	rightWall(false),
	leftWall(false),
	dv(0, 0)
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

void collision::collideBalls(sf::Vector2f ThisBallPos, sf::Vector2f OtherBallPos,
	float ThisBallMass, float OtherBallMass, sf::Vector2f ThisBallSpeed, 
	sf::Vector2f OtherBallSpeed, float ThisBallRadius, float OtherBallRadius)
{
	if (!isEnoughClose(ThisBallPos, OtherBallPos, ThisBallRadius, OtherBallRadius))
		return;
	else if (checkSpeedDirect(ThisBallSpeed, OtherBallSpeed, ThisBallPos, OtherBallPos))
		return;

	sf::Vector2f DeltaSpeed = ThisBallSpeed - OtherBallSpeed;
	sf::Vector2f n = norm(ThisBallPos - OtherBallPos);
	float ReducedMass = ThisBallMass * OtherBallMass / (ThisBallMass + OtherBallMass);
	float scal = MultScal(2.f * DeltaSpeed * ReducedMass, n);
	sf::Vector2f dp(scal * n.x, scal * n.y);
	dv += dp / (ThisBallMass);
}

bool collision::isEnoughClose(sf::Vector2f ThisBallPos, sf::Vector2f OtherBallPos,
	float ThisBallRadius, float OtherBallRadius)
{
	if (square(ThisBallPos - OtherBallPos) > (ThisBallRadius + OtherBallRadius) * (ThisBallRadius + OtherBallRadius))
		return false;
	else return true;
}

bool collision::checkSpeedDirect(sf::Vector2f ThisBallSpeed, sf::Vector2f OtherBallSpeed,
	sf::Vector2f ThisBallPos, sf::Vector2f OtherBallPos)
{
	if (MultScal(ThisBallSpeed - OtherBallSpeed, ThisBallPos - OtherBallPos) > 0)
		return true;
	else return false;
}


void collision::update(sf::Vector2f & velocity, int ball_number)
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
	//debug(ball_number, velocity);
	velocity -= dv;
	dv = { 0, 0 };
}

void collision::debug(int ball_number, sf::Vector2f const velocity)
{
	std::cout << ball_number << ":" << std::endl;
	std::cout << "velocity" << " : " << velocity.x << " " << velocity.y << std::endl;
	std::cout << "dv" << " : " << dv.x << " " << dv.y << std::endl << std::endl;
	std::cout << velocity.x << " - " << dv.x << std::endl << std::endl;
}

