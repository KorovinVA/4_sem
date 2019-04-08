#pragma once

#include "../../World/headers/Entity.h"
#include "../../Resources/ResourceHolder.h"
#include "Animation.h"
#include "Assaulter.h"

class Golem : public SceneNode, public Entity, public Animation, public Assaulter
{
public:
	Golem(TextureHolder * Textures);

	void drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const;
	void updateCurrent(sf::Time dt) override;
	unsigned int getCategory();
private:
	void getTextures(TextureHolder * Textures);
	void getIdleText(TextureHolder * Textures);
	void getRunText(TextureHolder * Textures);
	void getAttackText(TextureHolder * Textures);
};