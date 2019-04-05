#pragma once
#include <queue>

#include "../../World/headers/Entity.h"
#include "../../Resources/ResourceHolder.h"
#include "Animation.h"

class Knight : public Entity
{
public:
	typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
public:
	Knight(TextureHolder * Textures);

	virtual void drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const;
	void update();
	
	virtual unsigned int getCategory();
private:
	void updateIdle();
	void updateRun();
	void updateAttack();

	void getTextures(TextureHolder * Textures);
	void getIdleText(TextureHolder * Textures);
	void getRunText(TextureHolder * Textures);
	void getAttackText(TextureHolder * Textures);

	void createSpriteOrientation();
private:
	sf::Sprite Sprite;
	sf::Texture CurrentText;

	std::queue<sf::Texture> Idle;
	std::queue<sf::Texture> Run;
	std::queue<sf::Texture> Attack;
};