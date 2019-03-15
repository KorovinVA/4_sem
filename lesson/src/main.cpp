#include <SFML\Graphics.hpp>

void draw_arrow(sf::RenderWindow & window, int posx, int posy);

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 720), "My window");
	window.clear(sf::Color::Color(50, 50, 50));
	sf::CircleShape arrow(0);

	sf::Texture texture;
	texture.loadFromFile("bird.png");
	sf::Sprite circle(texture);
	circle.setScale(0.5f, 0.5f);


	sf::Vector2u circleSize = circle.getTexture()->getSize();
	circle.setOrigin(circleSize.x / 2, circleSize.y / 2);

	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f center = circle.getPosition();
	sf::Vector2f d = sf::Vector2f(mousePosition.x, mousePosition.y);

	const float Pi = 3.14159f;
	circle.setRotation(90 + atan2f(d.y, d.x) * 180 / Pi);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
		{
			circle.move(-1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			circle.move(1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			circle.move(0, -1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			circle.move(0, 1);
		}

		circleSize = circle.getTexture()->getSize();
		circle.setOrigin(circleSize.x / 2, circleSize.y / 2);
		mousePosition = sf::Mouse::getPosition(window);
		center = circle.getPosition();
		d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;
		circle.setRotation(90 + atan2f(d.y, d.x) * 180 / Pi);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(center.x, center.y), sf::Color::Yellow),
				sf::Vertex(sf::Vector2f(mousePosition.x + 1000, mousePosition.y + 1000 * mousePosition.y/mousePosition.x), sf::Color::Yellow),
			};
			window.draw(line, 2, sf::Lines);
			//texture1.loadFromFile("bird.png");
			//sf::Sprite circle(line);
			window.display();
			sf::sleep(sf::milliseconds(100));
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			int i = 0;
			sf::CircleShape circle2(10);
			circle2.setFillColor(sf::Color::Red);
			circle2.setPosition(center);
			window.draw(circle2);
			window.display();
			sf::sleep(sf::milliseconds(10));
			while (i < 100) {
				sf::sleep(sf::milliseconds(10));
				circle2.move(mousePosition.x/50, mousePosition.y/50);
				sf::sleep(sf::milliseconds(10));

				circleSize = circle.getTexture()->getSize();
				circle.setOrigin(circleSize.x / 2, circleSize.y / 2);
				mousePosition = sf::Mouse::getPosition(window);
				center = circle.getPosition();
				d = sf::Vector2f(1, mousePosition.y/mousePosition.x) - center;
				circle.setRotation(90 + atan2f(d.y, d.x) * 180 / Pi);

				window.clear(sf::Color::Color(50, 50, 50));
				window.draw(circle2);
				window.draw(circle);
				window.display();

				i++;
			}
		}

		window.clear(sf::Color::Color(50,50,50));
		window.draw(circle);
		//window.draw(arrow);
		window.display();
	}

	return 0;
}

void draw_arrow(sf::RenderWindow & window, int posx, int posy)
{
	sf::CircleShape circle(5);
	circle.setFillColor(sf::Color::Red);
	//circle.setOrigin(circle.getPosition().x, circle.getPosition().y);
	window.draw(circle);
	window.display();
	sf::sleep(sf::milliseconds(100));
}