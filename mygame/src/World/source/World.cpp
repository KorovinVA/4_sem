#include "../headers/World.h"
#include "../headers/SpriteNode.h"

World::World(sf::RenderWindow & window) :
	Window(window),
	WorldView(window.getDefaultView()),
	WorldBounds(
		0.f, // left X position
		0.f, // top Y position
		WorldView.getSize().x, // width
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
	PlayerKnight->setVelocity(0.f, 0.f);
	while (!CommandQueue.empty()) {
		Command CurrentCommand = CommandQueue.front();
		CommandQueue.pop();
		SceneGraph.onCommand(CurrentCommand, dt);
	}
	SceneGraph.update(dt);
}

void World::draw()
{
	Window.setView(WorldView);
	Window.draw(SceneGraph);
}

std::queue<Command>& World::getCommandQueue()
{
	return CommandQueue;
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

	std::unique_ptr<Warrior> golem(new Warrior(&Textures, Warrior::Golem));
	SceneLayers[Wildfowl]->attachChild(std::move(golem));
	SceneLayers[Wildfowl]->setPosition(WorldView.getSize().x / 2, WorldView.getSize().y - 140.f);

	std::unique_ptr<Warrior> hero(new Warrior(&Textures, Warrior::Knight));
	PlayerKnight = hero.get();
	PlayerKnight->setVelocity(0, 0);
	SceneLayers[Hero]->attachChild(std::move(hero));
	SceneLayers[Hero]->setPosition(SpawnPosition.x, WorldView.getSize().y - 140.f);
}

void World::loadTextures()
{
	Textures.load(Textures::Landscape, "../media/textures/background/PNG/game_background_1/game_background_1.png");

	Textures.load(Textures::Knight_Idle_1_000, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_000.png");
	Textures.load(Textures::Knight_Idle_1_001, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_001.png");
	Textures.load(Textures::Knight_Idle_1_002, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_002.png");
	Textures.load(Textures::Knight_Idle_1_003, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_003.png");
	Textures.load(Textures::Knight_Idle_1_004, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_004.png");
	Textures.load(Textures::Knight_Idle_1_005, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_005.png");
	Textures.load(Textures::Knight_Idle_1_006, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_006.png");

	Textures.load(Textures::Knight_Run_1_000, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_000.png");
	Textures.load(Textures::Knight_Run_1_001, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_001.png");
	Textures.load(Textures::Knight_Run_1_002, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_002.png");
	Textures.load(Textures::Knight_Run_1_003, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_003.png");
	Textures.load(Textures::Knight_Run_1_004, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_004.png");
	Textures.load(Textures::Knight_Run_1_005, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_005.png");
	Textures.load(Textures::Knight_Run_1_006, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_006.png");

	Textures.load(Textures::Knight_Attack_1_000, "../media/textures/knight/_PNG/1_KNIGHT/_ATTACK/ATTACK_000.png");
	Textures.load(Textures::Knight_Attack_1_001, "../media/textures/knight/_PNG/1_KNIGHT/_ATTACK/ATTACK_001.png");
	Textures.load(Textures::Knight_Attack_1_002, "../media/textures/knight/_PNG/1_KNIGHT/_ATTACK/ATTACK_002.png");
	Textures.load(Textures::Knight_Attack_1_003, "../media/textures/knight/_PNG/1_KNIGHT/_ATTACK/ATTACK_003.png");
	Textures.load(Textures::Knight_Attack_1_004, "../media/textures/knight/_PNG/1_KNIGHT/_ATTACK/ATTACK_004.png");
	Textures.load(Textures::Knight_Attack_1_005, "../media/textures/knight/_PNG/1_KNIGHT/_ATTACK/ATTACK_005.png");
	Textures.load(Textures::Knight_Attack_1_006, "../media/textures/knight/_PNG/1_KNIGHT/_ATTACK/ATTACK_006.png");
	Textures.load(Textures::Knight_Attack_1_007, "../media/textures/knight/_PNG/1_KNIGHT/_ATTACK/ATTACK_007.png");

	Textures.load(Textures::Golem_Idle_1_000, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_000.png");
	Textures.load(Textures::Golem_Idle_1_001, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_001.png");
	Textures.load(Textures::Golem_Idle_1_002, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_002.png");
	Textures.load(Textures::Golem_Idle_1_003, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_003.png");
	Textures.load(Textures::Golem_Idle_1_004, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_004.png");
	Textures.load(Textures::Golem_Idle_1_005, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_005.png");
	Textures.load(Textures::Golem_Idle_1_006, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_006.png");
	Textures.load(Textures::Golem_Idle_1_007, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_007.png");
	Textures.load(Textures::Golem_Idle_1_008, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_008.png");
	Textures.load(Textures::Golem_Idle_1_009, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_009.png");
	Textures.load(Textures::Golem_Idle_1_010, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_010.png");
	Textures.load(Textures::Golem_Idle_1_011, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_011.png");
	Textures.load(Textures::Golem_Idle_1_012, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_012.png");
	Textures.load(Textures::Golem_Idle_1_013, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_013.png");
	Textures.load(Textures::Golem_Idle_1_014, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_014.png");
	Textures.load(Textures::Golem_Idle_1_015, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_015.png");
	Textures.load(Textures::Golem_Idle_1_016, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_016.png");
	Textures.load(Textures::Golem_Idle_1_017, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Idle Blinking/0_Golem_Idle Blinking_017.png");

	Textures.load(Textures::Golem_Run_1_000, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Running/0_Golem_Running_000.png");
	Textures.load(Textures::Golem_Run_1_001, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Running/0_Golem_Running_001.png");
	Textures.load(Textures::Golem_Run_1_002, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Running/0_Golem_Running_002.png");
	Textures.load(Textures::Golem_Run_1_003, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Running/0_Golem_Running_003.png");
	Textures.load(Textures::Golem_Run_1_004, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Running/0_Golem_Running_004.png");
	Textures.load(Textures::Golem_Run_1_005, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Running/0_Golem_Running_005.png");
	Textures.load(Textures::Golem_Run_1_006, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Running/0_Golem_Running_006.png");
	Textures.load(Textures::Golem_Run_1_007, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Running/0_Golem_Running_007.png");
	Textures.load(Textures::Golem_Run_1_008, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Running/0_Golem_Running_008.png");
	Textures.load(Textures::Golem_Run_1_009, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Running/0_Golem_Running_009.png");
	Textures.load(Textures::Golem_Run_1_010, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Running/0_Golem_Running_010.png");
	Textures.load(Textures::Golem_Run_1_011, "../media/textures/golem/Golem_3/PNG/PNG Sequences/Running/0_Golem_Running_011.png");
}