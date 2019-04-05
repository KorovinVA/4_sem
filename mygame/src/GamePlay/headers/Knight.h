#pragma once
#include <queue>

#include "../../World/headers/Entity.h"
#include "../../Resources/ResourceHolder.h"
#include "Animation.h"
#include "Assaulter.h"

class Knight : public Entity, public Animation, public Assaulter
{
public:
	typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
public:
	Knight(TextureHolder * Textures);

	virtual void drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const;
	void update(sf::Time dt);
	
	virtual unsigned int getCategory();
private:
	void getTextures(TextureHolder * Textures);
	void getIdleText(TextureHolder * Textures);
	void getRunText(TextureHolder * Textures);
	void getAttackText(TextureHolder * Textures);

	void createSpriteOrientation();
};