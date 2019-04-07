#include "..\headers\StateStack.h"

StateStack::StateStack(sf::RenderWindow & window, TextureHolder & textures, FontHolder & fonts, Player & player):
	context(window, textures, fonts, player)
{
}

void StateStack::handleEvent(sf::Event & event)
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
	applyPendingChange();
}

void StateStack::draw()
{
	for (auto p = Conditions.begin(); p != Conditions.end(); ++p)
	{
		(*p)->draw();
	}
}

bool StateStack::isEmpty()
{
	return Conditions.empty();
}

void StateStack::pushState(States::ID StateID)
{
	PendingList.push_back(PendingChange(Push, StateID));
}

void StateStack::popState()
{
	PendingList.push_back(PendingChange(Pop));
}

void StateStack::clearStates()
{
	PendingList.push_back(PendingChange(Clear));
}

State::Ptr StateStack::createState(States::ID stateID)
{
	auto found = Keeper.find(stateID);
	if (found == Keeper.end()) exit(25);
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

StateStack::PendingChange::PendingChange(Action action_, States::ID stateID_)
{
	action = action_;
	stateID = stateID_;
}
