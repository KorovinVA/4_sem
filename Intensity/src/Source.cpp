// vs2017project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "charge.h"
#include <vector>
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Vertex.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
	//sf::CircleShape triangle(200, 3);
	charge a(5, -100, -500);
	charge b(-5, -400, -100);
	//sf::CircleShape circle(10);
	//circle.setOrigin(-300, -300);
	//circle.setFillColor(sf::Color::Blue);
	//sf::Vertex vertices[] =
	//{
		//sf::Vertex(sf::Vector2f(10,   10), sf::Color::Black),
		//sf::Vertex(sf::Vector2f(10, 110), sf::Color::Black),
	//};


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//window.draw(triangle);
		//window.draw(circle);
		window.clear(sf::Color::White);
		//window.draw(vertices, 2, sf::Lines);
		a.draw(window);
		b.draw(window);
		//sf::Vector2i pos = sf::Mouse::getPosition(window);
		//std::cout << pos.x << ":" << pos.y << std::endl;
		window.display();
		//sf::sleep(sf::milliseconds(1000));
	}
	return 0;
}