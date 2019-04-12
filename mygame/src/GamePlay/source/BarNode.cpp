#include "..\headers\BarNode.h"
#include <iostream>

BarNode::BarNode(sf::Color color) :
	BarLength(100.f)
{
	bar.setSize(sf::Vector2f(BarLength, 15.f));
	bar.setFillColor(color);
}

void BarNode::resizeBar(int value)
{
	BarLength = BarLength - (float)value;
	if (BarLength < 0) exit(25);
	bar.setSize(sf::Vector2f(BarLength, 15.f));
}

void BarNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(bar, states);
}
