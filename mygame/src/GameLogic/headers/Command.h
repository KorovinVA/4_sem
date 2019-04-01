#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

namespace Category {
	enum Type
	{
		None,
		Scene,
		Knight,
		Enemy,
		Enviroment
	};
}

class SceneNode;
class Command {
public:
	Command();
	std::function<void(SceneNode&, sf::Time)> action;
public:
	Category::Type category;
};