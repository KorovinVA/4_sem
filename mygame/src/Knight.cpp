#include "Knight.h"

Knight::Knight(const TextureHolder & textures) : Sprite(textures.get(Textures::Hero_Idle_000_Left))
{
	sf::FloatRect bounds = Sprite.getLocalBounds();
	Sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Knight::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(Sprite, states);
}
