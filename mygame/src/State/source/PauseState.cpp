#include "..\headers\State.h"
#include "..\headers\StateStack.h"
#include "../headers/PauseState.h"

PauseState::PauseState(StateStack & stack, Context context):
	State(stack, context)
{
	sf::Font& font = context.fonts->get(Fonts::MainMenu);
	sf::Vector2f viewSize = context.window->getView().getSize();

	PauseText.setFont(font);
	PauseText.setString("Game Paused");
	PauseText.setCharacterSize(70);
	PauseText.setPosition(0.27f * viewSize.x, 0.25f * viewSize.y);

	InstructionText.setFont(font);
	InstructionText.setString("(Press Backspace to return to the main menu or ESC to continue)");
	InstructionText.setPosition(0.f * viewSize.x, 0.6f * viewSize.y);
}

void PauseState::draw()
{
	sf::RenderWindow& window = *getContex().window;
	window.setView(window.getDefaultView());

	sf::RectangleShape backgroundShape;
	backgroundShape.setFillColor(sf::Color(0, 0, 0, 100));
	backgroundShape.setSize(window.getView().getSize());

	window.draw(backgroundShape);
	window.draw(PauseText);
	window.draw(InstructionText);
}

bool PauseState::update(sf::Time dt)
{
	return false;
}

bool PauseState::handleEvent(sf::Event & event)
{
	if (event.type != sf::Event::KeyPressed)
		return false;

	if (event.key.code == sf::Keyboard::Escape)
	{
		requestStackPop();
	}

	if (event.key.code == sf::Keyboard::BackSpace)
	{
		requestStateClear();
		requestStackPush(States::Menu);
	}
	return false;
}
