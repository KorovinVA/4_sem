#include "..\headers\StateStack.h"

void StateStack::handleEvent(const sf::Event & event)
{
	for (auto p = Conditions.rbegin(); p != Conditions.rend(); ++p) 
	{
		(*p)->handleEvent(event);
	}

}

void StateStack::update(sf::Time dt)
{
	for (auto p = Conditions.rbegin(); p != Conditions.rend(); ++p)
	{
		(*p)->update(dt);
	}
}

void StateStack::draw()
{
	for (auto p = Conditions.begin(); p != Conditions.end(); ++p)
	{
		(*p)->draw();
	}
}

State::Ptr StateStack::createState(States::ID stateID)
{
	auto found = Keeper.find(stateID);
	return found->second();
}

void StateStack::applyPendingChange()
{
	for (auto p = PendingList.begin(); p != PendingList.end(); ++p)
	{
		switch (p->action)
		{
		case Push:
			Conditions.push_back(createState(p->stateID));
			break;
		case Pop:
			Conditions.pop_back();
			break;
		case Clear:
			Conditions.clear();
			break;
		}
	}
	PendingList.clear();
}
