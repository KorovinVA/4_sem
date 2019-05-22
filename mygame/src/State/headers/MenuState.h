#pragma once
#pragma warning(disable: 4996)

#include <SFML/Graphics.hpp>
#include "State.h"


class MenuState : public State
{
public:
	enum OptionName
	{
		SinglePlay,
		OnlinePlay,
		Exit
	};
public:
	MenuState(StateStack& stack, Context context);
	void updateOptionText();

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(sf::Event& event);
private:
	sf::Sprite Background;
	std::vector<sf::Text> Options;
	sf::Text GameName;
	std::pair<size_t, bool> OptionIndex;
};