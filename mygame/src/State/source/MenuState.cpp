#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <iostream>

#include "..\headers\MenuState.h"

//constexpr 

MenuState::MenuState(StateStack & stack, Context context):
	State(stack, context),
	OptionIndex(0, false)
{
	sf::Vector2f viewSize = context.window->getView().getSize();
	sf::Texture& texture = context.textures->get(Textures::MainMenu);
	sf::Font& menu = context.fonts->get(Fonts::MainMenu);
	sf::Font& gameFont = context.fonts->get(Fonts::GameName);
	Background.setTexture(texture);

	GameName.setString("Overflow");
	GameName.setFont(gameFont);
	GameName.setOrigin(GameName.getLocalBounds().width / 2.f,
		GameName.getLocalBounds().height / 2.f);
	GameName.setCharacterSize(150);
	GameName.setPosition(viewSize.x / 2 - 220.f, viewSize.y / 2 - 300.f);
	sf::Color lightYellow(200, 245, 39, 255);
	GameName.setColor(lightYellow);

	sf::Text playOption;
	playOption.setString("Single Game");
	playOption.setFont(menu);
	playOption.setOrigin(playOption.getLocalBounds().width / 2.f, 
		playOption.getLocalBounds().height / 2.f);
	playOption.setPosition(viewSize.x / 2 , viewSize.y / 2);
	Options.push_back(playOption);
	
	sf::Text exitOption;
	exitOption.setString("Exit");
	exitOption.setFont(menu);
	exitOption.setOrigin(exitOption.getLocalBounds().width / 2.f,
		exitOption.getLocalBounds().height / 2.f);
	exitOption.setPosition(viewSize.x / 2.f,
		viewSize.y / 2.f + 2 * exitOption.getLocalBounds().height);
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
	window.draw(GameName);
	for (auto p = Options.begin(); p != Options.end(); p++)
	{
		window.draw(*p);
	}
}

bool MenuState::update(sf::Time dt)
{
	return true;
}

bool MenuState::handleEvent(sf::Event & event)
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
						requestStateClear();
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
	return true;
}
