#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <queue>

#include "../../Resources/ResourceHolder.h"
#pragma once
#include "../headers/SceneNode.h"
#include "../../Input/headers/Command.h"
#include "../../GamePlay/headers/Warrior.h"

class World
{
public:
	explicit World(sf::RenderWindow & window);
	void update(sf::Time dt);
	void draw();

	std::queue<Command> & getCommandQueue();
private:
	void processTheAttack();

	void buildScene();
	void guideEnimies();
	void loadTextures();
private:
	enum Layer
	{
		Background,
		Wildfowl,
		Hero,
		LayerCount
	};
private:
	sf::RenderWindow & Window;
	sf::View WorldView;
	TextureHolder Textures;
	SceneNode SceneGraph;
	std::array<SceneNode*, LayerCount> SceneLayers;

	sf::FloatRect WorldBounds;
	sf::Vector2f SpawnPosition;
	Warrior * PlayerKnight;

	std::queue<Command> CommandQueue;
	std::vector<Warrior*> Enemies;
};