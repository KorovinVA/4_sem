#include "../headers/SpriteNode.h"

SpriteNode::SpriteNode(const sf::Texture & texture) : Sprite(texture)
{
}

SpriteNode::SpriteNode(const sf::Texture & texture, const sf::IntRect & rect) : Sprite(texture)
{
}

void SpriteNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(Sprite, states);
}
