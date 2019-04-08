#include "..\headers\State.h"
#include "..\headers\StateStack.h"

State::State(StateStack & stack, Context context) :
	stack_(&stack),
	context(context)
{
}

void State::requestStackPush(States::ID stateID)
{
	stack_->pushState(stateID);
}

void State::requestStackPop()
{
	stack_->popState();
}

void State::requestStateClear()
{
	stack_->clearStates();
}

Context State::getContex() const
{
	return context;
}

