#pragma once
#include "StateStack.h"

class Application
{
private:
	void registerStates();
private:
	StateStack mStateStack;
};