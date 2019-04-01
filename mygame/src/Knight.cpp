#include "Knight.h"

constexpr float IDLE_FREQ = 0.13f;

Knight::Knight()
{
	loadTextures();
	Sprite.setTexture(Idle.front());
	sf::FloatRect bounds = Sprite.getLocalBounds();
	idleTime.restart();
}

void Knight::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(Sprite, states);
}

void Knight::loadTextures()
{
	loadIdleText();
}

void Knight::update()
{
	sf::Time timer = idleTime.getElapsedTime();
	if (timer.asSeconds() > IDLE_FREQ) {
		temp = Idle.front();
		Sprite.setTexture(temp);
		Idle.push(Idle.front());
		Idle.pop();
		idleTime.restart();
	}
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