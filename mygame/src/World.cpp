#include "World.h"
#include "SpriteNode.h"

World::World(sf::RenderWindow & window) :
	Window(window),
	WorldView(window.getDefaultView()),
	WorldBounds(
		0.f, // left X position
		-100.f, // top Y position
		5000.f, // width
		WorldView.getSize().y //height
	),
	SpawnPosition(
		0.f, // X
		WorldView.getSize().y// Y
	),
	PlayerKnight(nullptr)
{
	loadTextures();
	buildScene();
	WorldView.setCenter(WorldView.getSize().x / 2, WorldView.getSize().y / 2);
}

void World::update(sf::Time dt)
{
	PlayerKnight->update();
	SceneGraph.update(dt);
}

void World::draw()
{
	Window.setView(WorldView);
	Window.draw(SceneGraph);
}

void World::loadTextures()
{
	Textures.load(Textures::Landscape, "../media/textures/background/PNG/game_background_1/game_background_1.png");
}

void World::buildScene()
{
	for (int i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		SceneLayers[i] = layer.get();
		SceneGraph.attachChild(std::move(layer));
	}
	sf::Texture & texture = Textures.get(Textures::Landscape);
	sf::IntRect textureRect(WorldBounds);
	texture.setRepeated(true);

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(WorldBounds.left, WorldBounds.top);
	SceneLayers[Background]->attachChild(std::move(backgroundSprite));
	SceneLayers[Background]->setScale(0.8f, 0.8f);

	std::unique_ptr<Knight> hero(new Knight());
	PlayerKnight = hero.get();
	PlayerKnight->setVelocity(0, 0);
	SceneLayers[Hero]->attachChild(std::move(hero));
	SceneLayers[Hero]->setOrigin(0, 150);
	SceneLayers[Hero]->setPosition(SpawnPosition);
}
