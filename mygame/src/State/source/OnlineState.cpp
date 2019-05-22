#include "..\headers\OnlineState.h"

OnlineState::OnlineState(StateStack & stack, Context context) :
	State(stack, context)
{
}

void OnlineState::draw()
{
}

bool OnlineState::update(sf::Time dt)
{
	return true;
}

bool OnlineState::handleEvent(sf::Event & event)
{
	return true;
}
