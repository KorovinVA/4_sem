#pragma once
#include "charge.h"

double return_mod(double arg);
sf::Vector2i make_tension_line(charge * system, int charges_number, sf::Vector2i pos, sf::RenderWindow & window, int way, double intens_x_component, double intens_y_component);
sf::Vector2i calc_intensity(charge * system, sf::Vector2i pos, int charges_number, sf::RenderWindow & window, int way);
int return_sign(double x);
void create_dx_dy(int * dx, int * dy, double tan, double intens_x_component, double intens_y_component);