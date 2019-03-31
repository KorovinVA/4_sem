#include "World.h"
#include "SpriteNode.h"

World::World(sf::RenderWindow & window) :
	Window(window),
	WorldView(window.getDefaultView()),
	WorldBounds(
		0.f, // left X position
		0.f, // top Y position
		WorldView.getSize().x, // width
		2000.f
	),
	SpawnPosition(
		WorldView.getSize().x / 2.f, // X
		WorldBounds.height - WorldView.getSize().y // Y
	),
	PlayerKnight(nullptr)
{
	loadTextures();
	buildScene();
	WorldView.setCenter(SpawnPosition);
}

void World::update(sf::Time dt)
{
//	WorldView.move(0.f, mScrollSpeed * dt.asSeconds());
	sf::Vector2f position = PlayerKnight->getPosition();
	sf::Vector2f velocity = PlayerKnight->getVelocity();
	if (position.x <= WorldBounds.left + 150
		|| position.x >= WorldBounds.left + WorldBounds.width - 150)
	{
		velocity.x = -velocity.x;
		PlayerKnight->setVelocity(velocity);
	}
	SceneGraph.update(dt);
}

void World::draw()
{
	Window.setView(WorldView);
	//Window.draw(SceneGraph);

	Window.draw(SceneGraph);
}

void World::loadTextures()
{
	Textures.load(Textures::Landscape, "../media/textures/background/PNG/game_background_3/game_background_3.2.png");
	Textures.load(Textures::Hero_Idle_000_Left, "../media/textures/2D_KNIGHT__Idle_000.png");
	Textures.load(Textures::Hero_Idle_001_Left, "../media/textures/2D_KNIGHT__Idle_001.png");
	Textures.load(Textures::Hero_Idle_002_Left, "../media/textures/2D_KNIGHT__Idle_002.png");
	Textures.load(Textures::Hero_Idle_003_Left, "../media/textures/2D_KNIGHT__Idle_003.png");
	Textures.load(Textures::Hero_Idle_004_Left, "../media/textures/2D_KNIGHT__Idle_004.png");
	Textures.load(Textures::Hero_Idle_005_Left, "../media/textures/2D_KNIGHT__Idle_005.png");
	Textures.load(Textures::Hero_Idle_006_Left, "../media/textures/2D_KNIGHT__Idle_006.png");
	Textures.load(Textures::Hero_Idle_007_Left, "../media/textures/2D_KNIGHT__Idle_007.png");
}

void World::buildScene()
{
	for (int i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		SceneLayers[i] = layer.get();
		SceneGraph.attachChild(std::move(layer));
	}
	sf::Texture& texture = Textures.get(Textures::Landscape);
	sf::IntRect textureRect(WorldBounds);
	texture.setRepeated(true);

	std::unique_ptr<SpriteNode> backgroundSprite(
		new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(
		WorldBounds.left,
		600);
	SceneLayers[Background]->attachChild(std::move(backgroundSprite));

	std::unique_ptr<Knight> leader(
		new Knight(Textures));
	PlayerKnight = leader.get();
	PlayerKnight->setPosition(SpawnPosition);
	PlayerKnight->setVelocity(0, mScrollSpeed);
	SceneLayers[Hero]->attachChild(std::move(leader));
	//SceneLayers[Hero]->setScale(0.8f, 0.8f);
	SceneLayers[Hero]->setPosition(0, 0);
}
