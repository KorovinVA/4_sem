#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <iostream>

#include "..\headers\MenuState.h"

//constexpr 

MenuState::MenuState(StateStack & stack, Context context):
	State(stack, context),
	OptionIndex(0, false)
{
	if (!context.textures) exit(30);
	sf::Texture& texture = context.textures->get(Textures::MainMenu);
	sf::Font& font = context.fonts->get(Fonts::MainMenu);
	Background.setTexture(texture);

	sf::Text playOption;
	playOption.setString("Single Game");
	playOption.setFont(font);
	playOption.setOrigin(playOption.getLocalBounds().width / 2.f, 
		playOption.getLocalBounds().height / 2.f);
	playOption.setPosition(context.window->getDefaultView().getSize() / 2.f);
	Options.push_back(playOption);
	
	sf::Text exitOption;
	exitOption.setString("Exit");
	exitOption.setFont(font);
	exitOption.setOrigin(exitOption.getLocalBounds().width / 2.f,
		exitOption.getLocalBounds().height / 2.f);
	exitOption.setPosition(context.window->getDefaultView().getSize().x / 2.f, 
		context.window->getDefaultView().getSize().y / 2.f + 2 * exitOption.getLocalBounds().height);
	Options.push_back(exitOption);
}

void MenuState::updateOptionText()
{
	for (auto p = Options.begin(); p != Options.end(); p++)
	{
		p->setColor(sf::Color::White);
	}
	if (OptionIndex.second)
		Options[OptionIndex.first].setColor(sf::Color::Yellow);
}

void MenuState::draw()
{
	
	sf::RenderWindow& window = *getContex().window;
	window.draw(Background);
	for (auto p = Options.begin(); p != Options.end(); p++)
	{
		window.draw(*p);
	}
}

void MenuState::update(sf::Time dt)
{
}

void MenuState::handleEvent(sf::Event & event)
{
	sf::Vector2i MousePos = sf::Mouse::getPosition();
	bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	size_t ContainerSize = Options.size();
	for (size_t i = 0; i < ContainerSize; i++)
	{
		if (MousePos.y <= Options[i].getPosition().y + Options[i].getLocalBounds().height &&
			MousePos.y >= Options[i].getPosition().y - Options[i].getLocalBounds().height &&
			MousePos.x <= Options[i].getPosition().x + Options[i].getLocalBounds().width &&
			MousePos.x >= Options[i].getPosition().x - Options[i].getLocalBounds().width)
		{
			OptionIndex.first = i;
			OptionIndex.second = true;

			if (isPressed)
			{
				switch (i) {
					case OptionName::SinglePlay:
						requestStackPop();
						requestStackPush(States::Game);
						break;
					case OptionName::Exit:
						requestStackPop();
						getContex().window->close();
						break;
				}
			}
			break;
		}
		else
			OptionIndex.second = false;
	}
	updateOptionText();
}
