// vs2017project.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "charge.h"
#include <vector>
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Vertex.hpp>

sf::Vector2i calc_intensity(charge * system, sf::Vector2i pos, int charges_number, sf::RenderWindow & window, int size);

int main()
{
	int i = 0;
	sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
	charge a(5000, -500, -550);
	charge b(-5000, -500, -100);
	charge c(5000, -100, -300);

	charge system[3];
	system[0] = a;
	system[1] = b;
	system[2] = c;

	window.clear(sf::Color::Black);
	a.draw(window);
	b.draw(window);
	c.draw(window);
	window.display();

	while (window.isOpen())
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i first_pos = sf::Mouse::getPosition(window);
			auto second_pos = first_pos;
			//std::cout << first_pos.x << ":" << first_pos.y << std::endl;
			//return 0;
			sf::sleep(sf::milliseconds(100));
			//std::cout << pos.x << ":" << pos.y << std::endl;
			while (window.isOpen()) {

				sf::Event event;
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed)
						window.close();
				}
				a.draw(window);
				b.draw(window);
				c.draw(window);
				//window.clear(sf::Color::White);
				first_pos = calc_intensity(system, first_pos, 3, window, 1);
				second_pos = calc_intensity(system, second_pos, 3, window, 0);
				//std::cout << first_pos.x << ":" << first_pos.y << std::endl;
				sf::sleep(sf::milliseconds(50));
				window.display();
			}
		}
	}
	return 0;
}