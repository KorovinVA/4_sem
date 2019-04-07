#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "StateIdentifiers.h"
#include "Context.h"

class StateStack;

class State
{
public:
	typedef std::unique_ptr<State> Ptr;
public:
	explicit State(StateStack & stack, Context context);

	virtual void handleEvent(sf::Event & event) = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void draw() = 0;

protected:
	void requestStackPush(States::ID stateID);
	void requestStackPop();
	void requestStateClear();
	Context getContex() const;
private:
	StateStack* stack_;
	Context	context;
};