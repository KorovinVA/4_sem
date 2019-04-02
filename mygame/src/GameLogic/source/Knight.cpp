#include "../headers/Knight.h"
#include "../headers/Command.h"

constexpr float IDLE_FREQ = 0.13f;
constexpr float RUN_FREQ = 0.13f;

Knight::Knight()
{
	loadTextures();
	Sprite.setTexture(Idle.front());
	sf::FloatRect bounds = Sprite.getLocalBounds();

	moveRight.category = Category::Knight;
	moveRight.action = KnightMover(0, 0);

	idleTime.restart();
	runTime.restart();
}

void Knight::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(Sprite, states);
}

void Knight::loadTextures()
{
	loadIdleText();
	loadRunText();
}

void Knight::update()
{
	sf::Vector2f CurrentSpeed = getVelocity();
	Sprite.move(CurrentSpeed);
	if(CurrentSpeed.x == 0.f && CurrentSpeed.y == 0.f) updateIdle();
	else if (CurrentSpeed.y == 0.f) updateRun();
}

void Knight::updateIdle()
{
	sf::Time timer = idleTime.getElapsedTime();
	if (timer.asSeconds() > IDLE_FREQ) {
		CurrentText = Idle.front();
		Sprite.setTexture(CurrentText);
		Idle.push(Idle.front());
		Idle.pop();
		idleTime.restart();
	}
}

void Knight::updateRun()
{
	sf::Time timer = runTime.getElapsedTime();
	if (timer.asSeconds() > RUN_FREQ) {
		CurrentText = Run.front();
		Sprite.setTexture(CurrentText);
		Run.push(Run.front());
		Run.pop();
		runTime.restart();
	}
}

unsigned int Knight::getCategory()
{
	return Category::Knight;
}

void Knight::loadIdleText()
{
	Textures.load(Textures::Knight_Idle_1_000, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_000_.png");
	Idle.push(Textures.get(Textures::Knight_Idle_1_000));
	Textures.load(Textures::Knight_Idle_1_001, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_001_.png");
	Idle.push(Textures.get(Textures::Knight_Idle_1_001));
	Textures.load(Textures::Knight_Idle_1_002, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_002_.png");
	Idle.push(Textures.get(Textures::Knight_Idle_1_002));
	Textures.load(Textures::Knight_Idle_1_003, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_003_.png");
	Idle.push(Textures.get(Textures::Knight_Idle_1_003));
	Textures.load(Textures::Knight_Idle_1_004, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_004_.png");
	Idle.push(Textures.get(Textures::Knight_Idle_1_004));
	Textures.load(Textures::Knight_Idle_1_005, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_005_.png");
	Idle.push(Textures.get(Textures::Knight_Idle_1_005));
	Textures.load(Textures::Knight_Idle_1_006, "../media/textures/knight/_PNG/1_KNIGHT/_IDLE/_IDLE_006_.png");
	Idle.push(Textures.get(Textures::Knight_Idle_1_006));
}

void Knight::loadRunText()
{
	Textures.load(Textures::Knight_Run_1_000, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_000.png");
	Run.push(Textures.get(Textures::Knight_Run_1_000));
	Textures.load(Textures::Knight_Run_1_001, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_001.png");
	Run.push(Textures.get(Textures::Knight_Run_1_001));
	Textures.load(Textures::Knight_Run_1_002, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_002.png");
	Run.push(Textures.get(Textures::Knight_Run_1_002));
	Textures.load(Textures::Knight_Run_1_003, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_003.png");
	Run.push(Textures.get(Textures::Knight_Run_1_003));
	Textures.load(Textures::Knight_Run_1_004, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_004.png");
	Run.push(Textures.get(Textures::Knight_Run_1_004));
	Textures.load(Textures::Knight_Run_1_005, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_005.png");
	Run.push(Textures.get(Textures::Knight_Run_1_005));
	Textures.load(Textures::Knight_Run_1_006, "../media/textures/knight/_PNG/1_KNIGHT/_RUN/_RUN_006.png");
	Run.push(Textures.get(Textures::Knight_Run_1_006));
}
