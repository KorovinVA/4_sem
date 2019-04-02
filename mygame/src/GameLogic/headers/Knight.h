#pragma once
#include <queue>

#include "../../World/headers/Entity.h"
#include "../../Resources/ResourceHolder.h"
#include "KnightMover.h"

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
	void updateIdle();
	void updateRun();
	
	virtual unsigned int getCategory();
private:
	void loadIdleText();
	void loadRunText();
private:
	TextureHolder Textures;
	sf::Sprite Sprite;

	sf::Texture CurrentText;
	std::queue<sf::Texture> Idle;
	std::queue<sf::Texture> Run;

	Command moveRight;
};