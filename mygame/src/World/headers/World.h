#pragma once
#include <SFML/Graphics.hpp>
#include <array>

#include "../../Resources/ResourceHolder.h"
#include "../headers/SceneNode.h"
#include "../../GameLogic/headers/Knight.h"
#include "../../GameLogic/headers/Command.h"

class World
{
public:
	explicit World(sf::RenderWindow & window);
	void update(sf::Time dt);
	void draw();

	std::queue<Command> & getCommandQueue();
private:
	void buildScene();
	void loadTextures();
private:
	enum Layer
	{
		Background,
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
	//float mScrollSpeed;
	Knight * PlayerKnight;

	std::queue<Command> CommandQueue;
};