#pragma once

#include <map>
#include <stack>
#include <functional>
#include <SFML/Graphics.hpp>

#include "StateIdentifiers.h"
#include "State.h"

class State;
class StateStack
{
public:
	enum Action
	{
		Push,
		Pop,
		Clear
	};
public:
	explicit StateStack(sf::RenderWindow & window, TextureHolder & textures, FontHolder & fonts, Player & player);

	template <typename T>
	void registerState(States::ID stateID);

	void handleEvent(const sf::Event& event);
	void update(sf::Time dt);
	void draw();
	bool isEmpty();

	void pushState(States::ID StateID);
	void popState();
	void clearStates();
private:
	State::Ptr createState(States::ID stateID);
	void applyPendingChange();
private:
	struct PendingChange
	{
		PendingChange(Action action_, States::ID stateID_);
		Action action;
		States::ID stateID;
	};
private:
	std::map<States::ID, std::function<State::Ptr()>> Keeper;
	std::vector<State::Ptr> Conditions;
	std::vector<PendingChange> PendingList;
	Context context;
};

template<typename T>
inline void StateStack::registerState(States::ID stateID)
{
	Keeper[States::ID] = [this]()
	{
		return State::Ptr(new T(this, context));
	};
}
