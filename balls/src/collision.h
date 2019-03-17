#pragma once
#include <SFML/Graphics.hpp>
constexpr auto X_SCREEN_SIZE = 640;
constexpr auto Y_SCREEN_SIZE = 480;

class collision 
{
private:
	bool topWall;
	bool bottomWall;
	bool rightWall;
	bool leftWall;

	sf::Vector2f dv;
public:
	collision();
	void checkWall(sf::Vector2f const pos);

	void collideBalls(sf::Vector2f ThisBallPos, sf::Vector2f OtherBallPos,
		float ThisBallMass, float OtherBallMass, sf::Vector2f ThisBallSpeed,
		sf::Vector2f OtherBallSpeed, float ThisBallRadius, float OtherBallRadius);
	bool isEnoughClose(sf::Vector2f ThisBallPos, sf::Vector2f OtherBallPos,
		float ThisBallRadius, float OtherBallRadius);
	bool checkSpeedDirect(sf::Vector2f ThisBallSpeed, sf::Vector2f OtherBallSpeed,
		sf::Vector2f ThisBallPos, sf::Vector2f OtherBallPos);

	void update(sf::Vector2f & velocity, int ball_number);
	void debug(const int ball_number, sf::Vector2f const velocity);
};