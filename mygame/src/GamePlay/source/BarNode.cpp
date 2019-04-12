#include "..\headers\BarNode.h"

BarNode::BarNode(BarType type, float const & BarLength_) :
	BarLength(BarLength_)
{
	bar.setSize(sf::Vector2f(BarLength, 15.f));
	bar.setOutlineThickness(2.f);
	bar.setOutlineColor(sf::Color::Black);
	switch (type)
	{
	case HealthBar:
		bar.setFillColor(sf::Color(200, 0, 30, 255));
		bar.setPosition(0, -50);
		break;
	case StaminaBar:
		bar.setFillColor(sf::Color(0, 199, 53, 255));
		break;
	}
	bar.setSize(sf::Vector2f(BarLength, 15.f));
}

void BarNode::resizeBar(float value)
{
	BarLength = value;
	if (BarLength <= 0)
	{
		BarLength = 0.f;
		bar.setOutlineThickness(0.f);
	}
	bar.setSize(sf::Vector2f(BarLength, 15.f));
}

void BarNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(bar, states);
}
