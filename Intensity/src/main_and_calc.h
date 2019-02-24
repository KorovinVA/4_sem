#include "charge.h"

constexpr auto POSITIVE_PASS = 1;
constexpr auto NEGATIVE_PASS = 0;

sf::Vector2i calc_intensity(charge * system, sf::Vector2i pos, int charges_number, sf::RenderWindow & window, int way);