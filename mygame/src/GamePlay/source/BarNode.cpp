#include "..\headers\BarNode.h"

BarNode::BarNode(sf::Color color)
{
	bar.setSize(sf::Vector2f(100.f, 15.f));
	bar.setFillColor(color);
}

void BarNode::resizeBar()
{
}

void BarNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(bar, states);
}
