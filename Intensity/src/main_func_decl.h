#pragma once
#include "charge.h"

constexpr auto MAX_CHARGES_NUMBER = 10;
constexpr auto MOUSE_PRESS_WAIT = 100;
constexpr auto CHARGE_VAL = 1;

void check_closing(sf::Event event, sf::RenderWindow & window);
void create_pos_charge(charge * system, int * charges_num, sf::RenderWindow & window);
void create_neg_charge(charge * system, int * charges_num, sf::RenderWindow & window);