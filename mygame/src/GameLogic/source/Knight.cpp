#include "../headers/Knight.h"
#include "../headers/Command.h"

constexpr float IDLE_FREQ = 0.13f;
constexpr float RUN_FREQ = 0.13f;

Knight::Knight(TextureHolder * Textures)
{
	getTextures(Textures);
	Sprite.setTexture(Idle.front());
	sf::FloatRect bounds = Sprite.getLocalBounds();

	idleTime.restart();
	runTime.restart();
}

void Knight::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(Sprite, states);
}

void Knight::getTextures(TextureHolder * Textures)
{
	getIdleText(Textures);
	getRunText(Textures);
}

void Knight::update()
{
	sf::Vector2f CurrentSpeed = getVelocity();
	Sprite.move(CurrentSpeed);
	createSpriteOrientation();
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

void Knight::getIdleText(TextureHolder * Textures)
{
	Idle.push(Textures->get(Textures::Knight_Idle_1_000));
	Idle.push(Textures->get(Textures::Knight_Idle_1_001));
	Idle.push(Textures->get(Textures::Knight_Idle_1_002));
	Idle.push(Textures->get(Textures::Knight_Idle_1_003));
	Idle.push(Textures->get(Textures::Knight_Idle_1_004));
	Idle.push(Textures->get(Textures::Knight_Idle_1_005));
	Idle.push(Textures->get(Textures::Knight_Idle_1_006));
}

void Knight::getRunText(TextureHolder * Textures)
{
	Run.push(Textures->get(Textures::Knight_Run_1_000));
	Run.push(Textures->get(Textures::Knight_Run_1_001));
	Run.push(Textures->get(Textures::Knight_Run_1_002));
	Run.push(Textures->get(Textures::Knight_Run_1_003));
	Run.push(Textures->get(Textures::Knight_Run_1_004));
	Run.push(Textures->get(Textures::Knight_Run_1_005));
	Run.push(Textures->get(Textures::Knight_Run_1_006));
}

void Knight::createSpriteOrientation()
{
	if (isTurnedLeft())
		Sprite.setTextureRect(sf::IntRect(Sprite.getLocalBounds().width, 0, -Sprite.getLocalBounds().width,
			Sprite.getLocalBounds().height));
	else if (isTurnedRight())
		Sprite.setTextureRect(sf::IntRect(Sprite.getLocalBounds()));
}
