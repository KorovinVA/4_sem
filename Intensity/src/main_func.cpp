#include "main_func_decl.h"

void check_closing(sf::Event event, sf::RenderWindow & window) 
{
	if (event.type == sf::Event::Closed)
		window.close();
}

void check_charges_number(int number)
{
	if (number == MAX_CHARGES_NUMBER) exit(5);
}

void create_pos_charge(charge * system, int * charges_num, sf::RenderWindow & window)
{
	sf::sleep(sf::milliseconds(MOUSE_PRESS_WAIT));
	sf::Vector2i position = sf::Mouse::getPosition(window);
	system[*charges_num] = charge(CHARGE_VAL, (float)-position.x, (float)-position.y);
	(*charges_num)++;
	check_charges_number(*charges_num);
}

void create_neg_charge(charge * system, int * charges_num, sf::RenderWindow & window)
{
	sf::sleep(sf::milliseconds(MOUSE_PRESS_WAIT));
	sf::Vector2i position = sf::Mouse::getPosition(window);
	system[*charges_num] = charge(-CHARGE_VAL, (float)-position.x, (float)-position.y);
	(*charges_num)++;
	check_charges_number(*charges_num);
}