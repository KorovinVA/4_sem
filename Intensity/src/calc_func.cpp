#include <cmath>

#include "cal_func_decl.h"
#include "main_and_calc.h"

constexpr auto MAX_COORDINATE_CHANGE = 5;
constexpr auto MIN_COORDINATE_CHANE = 1;

double return_mod(double arg) 
{
	if (arg > 0) return arg;
	else return -arg;
}

float change_pos(int pos, int len, int way) {

	if (way == POSITIVE_PASS) return (float)(pos + len);
	else if( way == NEGATIVE_PASS) return (float)(pos - len);
}

int return_sign(double x) {

	return (int)(x / return_mod(x));
}

void create_dx_dy(int * dx, int * dy, double tan, double intens_x_component, double intens_y_component) 
{
	if (return_mod(tan) > 1)
	{
		*dx = return_sign(intens_x_component) * MIN_COORDINATE_CHANE;
		*dy = (int)(tan * *dx);
		if (*dy > MAX_COORDINATE_CHANGE || *dy < -MAX_COORDINATE_CHANGE)
		{
			*dy = return_sign(tan) * MAX_COORDINATE_CHANGE * *dx;
		}
	}
	else
	{
		*dy = return_sign(intens_y_component) * MIN_COORDINATE_CHANE;
		*dx = (int)(*dy / tan);
		if (*dx > MAX_COORDINATE_CHANGE || *dx < -MAX_COORDINATE_CHANGE)
		{
			*dx = return_sign(tan) * MAX_COORDINATE_CHANGE * *dy;
		}
	}
}

sf::Vector2i make_tension_line(charge * system, int charges_number, sf::Vector2i pos, sf::RenderWindow & window, int way, double intens_x_component, double intens_y_component)
{
	int dx = 0;
	int dy = 0;
	double tan = 0;

	if (intens_x_component)
	{
		tan = intens_y_component / intens_x_component;
		create_dx_dy(&dx, &dy, tan, intens_x_component, intens_y_component);
	}
	else 
	{
		dy = MAX_COORDINATE_CHANGE * return_sign(intens_y_component);
	}

	//Draw a tension line
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f((float)pos.x, (float)pos.y), sf::Color::White),
		sf::Vertex(sf::Vector2f(change_pos(pos.x, dx, way), change_pos(pos.y, dy, way)), sf::Color::White),
	};
	window.draw(line, 2, sf::Lines);

	pos.x = (int)change_pos(pos.x, dx, way);
	pos.y = (int)change_pos(pos.y, dy, way);
	return pos;
}

sf::Vector2i calc_intensity(charge * system, sf::Vector2i pos, int charges_number, sf::RenderWindow & window, int way)
{
	std::pair<double, double> intensity(0, 0);

	for (int i = 0; i < charges_number; i++) {
		double dx = system[i].get_x() + pos.x;
		double dy = system[i].get_y() + pos.y;
		intensity.first += system[i].get_val() * dx /
			std::pow(dx * dx + dy * dy, 1.5);
	}
	for (int i = 0; i < charges_number; i++) {
		double dx = system[i].get_x() + pos.x;
		double dy = system[i].get_y() + pos.y;
		intensity.second += system[i].get_val() * dy /
			std::pow(dx * dx + dy * dy, 1.5);
	}

	pos = make_tension_line(system, charges_number, pos, window, way, intensity.first, intensity.second);	
	return pos;
}
