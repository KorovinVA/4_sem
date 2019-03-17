#include "mathfunctions.h"
#include <cmath>

float square(sf::Vector2f const vec)
{
	return (vec.x * vec.x + vec.y * vec.y);
}

float MultScal(sf::Vector2f one, sf::Vector2f two)
{
	return one.x * two.x + one.y * two.y;
}

sf::Vector2f norm(sf::Vector2f vec)
{
	float mod = sqrt(vec.x * vec.x + vec.y * vec.y);
	vec.x = vec.x / mod;
	vec.y = vec.y / mod;
	return vec;
}
