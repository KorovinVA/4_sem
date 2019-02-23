#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Vertex.hpp>
#include "charge.h"
#include <iostream>
#include <cmath>
#include "vector2.h"

sf::Vector2i calc_intensity(charge * system, sf::Vector2i pos, int charges_number, sf::RenderWindow & window, int side);

double return_mod(double arg) 
{
	if (arg > 0) return arg;
	else return -arg;
}

int change_pos(int pos, int len, int side) {
	if (side) return pos + len;
	else return pos - len;
}

sf::Vector2i make_tension_line(charge * system, double tan, int charges_number, sf::Vector2i pos, sf::RenderWindow & window, int side, double x_component, double y_component)
{
	int x_len = 0;
	int y_len = 0;
	if (return_mod(tan) > 1)
	{
		x_len = x_component/return_mod(x_component);
		y_len = tan * x_len;
		if (y_len > 10 || y_len < -10) y_len = tan/return_mod(tan) * 10 * x_len;
	}
	else
	{
		y_len = y_component/return_mod(y_component);
		x_len = y_len / tan;
		if (x_len > 10 || x_len < -10) x_len = tan / return_mod(tan) * 10 * y_len;
	}
	std::cout << x_len << "||" << y_len << std::endl;
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(pos.x, pos.y), sf::Color::White),
		sf::Vertex(sf::Vector2f(change_pos(pos.x, x_len, side), change_pos(pos.y, y_len, side)), sf::Color::White),
	};
	window.draw(line, 2, sf::Lines);
	//if (return_mod(double(pos.x + x_len)) < 1000 && return_mod(double(pos.y + y_len)) < 600) 
	//{
	pos.x = change_pos(pos.x, x_len, side);
	pos.y = change_pos(pos.y, y_len, side);
	//}
	return pos;
}

sf::Vector2i calc_intensity(charge * system, sf::Vector2i pos, int charges_number, sf::RenderWindow & window, int side)
{
	double tan = 0;
	std::pair<double, double> components(0, 0);
	for (int i = 0; i < charges_number; i++) {
		double dx = system[i].get_x() + pos.x;
		double dy = system[i].get_y() + pos.y;
		components.first += system[i].get_val() * dx /
			std::pow(dx * dx + dy * dy, 1.5);
	}
	for (int i = 0; i < charges_number; i++) {
		double dx = system[i].get_x() + pos.x;
		double dy = system[i].get_y() + pos.y;
		components.second += system[i].get_val() * dy /
			std::pow(dx * dx + dy * dy, 1.5);
	}
	std::cout << components.first << ' ' << components.second << std::endl;
	vector intensity(components.first, components.second);
	if(intensity.get_y() * intensity.get_x() > 0) tan = 100;
	else tan = -100;
	if (intensity.get_x()) tan = intensity.get_y() / intensity.get_x();
	pos = make_tension_line(system, tan, charges_number, pos, window, side, components.first, components.second);	
	return pos;
	//std::cout << intensity.get_x() << ":" << intensity.get_y() << std::endl;

}
