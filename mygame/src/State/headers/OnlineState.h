#pragma once
#pragma warning(disable: 4996)

#include <SFML/Graphics.hpp>
#include "State.h"


class OnlineState : public State
{
public:
	OnlineState(StateStack & stack, Context context);
	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(sf::Event& event);
};