#pragma once
#include "Entity.h"
#include "ResourceHolder.h"

class Knight : public Entity
{
public:
	typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
public:
	Knight(const TextureHolder & textures);
	virtual void drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const;
private:
	sf::Sprite Sprite;
};