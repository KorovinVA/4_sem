#include "charge.h"
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Vertex.hpp>

constexpr auto BALL_RADIUS = 10;

void charge::draw(sf::RenderWindow &window)
{
	is_positive() == true ? make_pos(window) : make_neg(window);
}

void charge::make_pos(sf::RenderWindow & window)
{
	sf::CircleShape circle(BALL_RADIUS);
	sf::Vertex first_sign_line[] =
	{
		sf::Vertex(sf::Vector2f(-x_ + BALL_RADIUS / 2 , -y_ + BALL_RADIUS), sf::Color::Black),
		sf::Vertex(sf::Vector2f(-x_ + 1.5 * BALL_RADIUS, -y_ + BALL_RADIUS), sf::Color::Black),
	};
	sf::Vertex second_sign_line[] = 
	{
		sf::Vertex(sf::Vector2f(-x_ + BALL_RADIUS, -y_ + BALL_RADIUS / 2), sf::Color::Black),
		sf::Vertex(sf::Vector2f(-x_ + BALL_RADIUS, -y_ + 1.5 * BALL_RADIUS), sf::Color::Black),
	};
	circle.setOrigin(x_, y_);
	circle.setFillColor(sf::Color::Red);
	window.draw(circle);
	window.draw(first_sign_line, 2, sf::Lines);
	window.draw(second_sign_line, 2, sf::Lines);
}

void charge::make_neg(sf::RenderWindow & window)
{
	sf::CircleShape circle(BALL_RADIUS);
	sf::Vertex sign_line[] =
	{
		sf::Vertex(sf::Vector2f(-x_ + BALL_RADIUS / 2 , -y_ + BALL_RADIUS), sf::Color::Black),
		sf::Vertex(sf::Vector2f(-x_ + 1.5 * BALL_RADIUS, -y_ + BALL_RADIUS), sf::Color::Black),
	};
	circle.setOrigin(x_, y_);
	circle.setFillColor(sf::Color::Blue);
	window.draw(circle);
	window.draw(sign_line, 2, sf::Lines);
}

charge::charge(float val, float x, float y)
{
	val_ = val;
	x_ = x;
	y_ = y;
}

bool charge::is_positive()
{	
	if (val_ >= 0) return true;
	return false;
}

float charge::get_x()
{
	return x_;
}

float charge::get_y()
{
	return y_;
}

float charge::get_val()
{
	return val_;
}

