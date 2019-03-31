#pragma once
#include <SFML/Graphics.hpp>
#include <array>

#include "ResourceHolder.h"
#include "SceneNode.h"
#include "Knight.h"

class World
{
public:
	typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
public:
	explicit World(sf::RenderWindow & window);
	void update(sf::Time dt);
	void draw();
private:
	void loadTextures();
	void buildScene();
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
	float mScrollSpeed;
	Knight * PlayerKnight;
};