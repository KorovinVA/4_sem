#include "main_func_decl.h"
#include "main_and_calc.h"

constexpr auto SCREEN_REFRESH_TIME = 50;

int main()
{
	int charges_num = 0;
	charge system[MAX_CHARGES_NUMBER];
	sf::Event event;

	sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
	window.clear(sf::Color::Black);
	window.display();

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			check_closing(event, window);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) 
		{
			create_pos_charge(system, &charges_num, window);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			create_neg_charge(system, &charges_num, window);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
		{
			sf::Vector2i pos_intens_direct = sf::Mouse::getPosition(window);
			auto neg_intens_direct = pos_intens_direct;
			sf::sleep(sf::milliseconds(MOUSE_PRESS_WAIT));

			while (window.isOpen()) 
			{
				while (window.pollEvent(event)) 
				{
					check_closing(event, window);
				}
				for (int i = 0; i < charges_num; i++) 
				{
					system[i].draw(window);
				}
				pos_intens_direct = calc_intensity(system, pos_intens_direct, charges_num, window, POSITIVE_PASS);
				neg_intens_direct = calc_intensity(system, neg_intens_direct, charges_num, window, NEGATIVE_PASS);
				sf::sleep(sf::milliseconds(SCREEN_REFRESH_TIME));
				window.display();
			}
		}
		for (int i = 0; i < charges_num; i++)
		{
			system[i].draw(window);
		}

		window.display();
	}
	return 0;
}