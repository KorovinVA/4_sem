#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Vertex.hpp>

class charge
{
	float x_;
	float y_;
	float val_;
public:
	charge(): x_(0), y_(0), val_(0) {};
	charge(float val, float x, float y);
	void draw(sf::RenderWindow &window);
	void make_pos(sf::RenderWindow &window);
	void make_neg(sf::RenderWindow &window);
	bool is_positive();
	float get_x();
	float get_y();
	float get_val();
};

