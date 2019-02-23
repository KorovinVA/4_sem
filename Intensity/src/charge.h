#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Vertex.hpp>

class charge
{
	float x_;
	float y_;
	float val_;
public:
	charge(float val, float x, float y);
	void draw(sf::RenderWindow &window);
	void make_pos(sf::RenderWindow &window);
	void make_neg(sf::RenderWindow &window);
	bool is_positive();
};

