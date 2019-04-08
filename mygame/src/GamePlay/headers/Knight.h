#pragma once
#include <queue>

#include "../../World/headers/Entity.h"
#include "../../Resources/ResourceHolder.h"
#include "Animation.h"
#include "Assaulter.h"

class Knight : public SceneNode, public Entity, public Animation, public Assaulter
{
public:
	Knight(TextureHolder * Textures);

	void drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const;
	void update(sf::Time dt);
	unsigned int getCategory();
private:
	void getTextures(TextureHolder * Textures);
	void getIdleText(TextureHolder * Textures);
	void getRunText(TextureHolder * Textures);
	void getAttackText(TextureHolder * Textures);
};