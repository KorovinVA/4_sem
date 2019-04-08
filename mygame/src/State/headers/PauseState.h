#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"

class PauseState : public State
{
public:
	PauseState(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(sf::Event & event);

private:
	sf::Sprite BackgroundSprite;
	sf::Text PauseText;
	sf::Text InstructionText;
};