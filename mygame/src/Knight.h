#pragma once
#include <queue>

#include "Entity.h"
#include "ResourceHolder.h"

class Knight : public Entity
{
public:
	typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
public:
	Knight();
	virtual void drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const;
	void loadTextures();
	void update();
private:
	void loadIdleText();
private:
	TextureHolder Textures;
	sf::Sprite Sprite;

	sf::Texture temp;
	std::queue<sf::Texture> Idle;
	sf::Clock idleTime;
};