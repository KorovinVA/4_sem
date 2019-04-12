#pragma once
#include "../../World/headers/SceneNode.h"

class BarNode : public SceneNode
{
public:
	explicit BarNode(sf::Color color);

	void resizeBar(int value);
private:
	virtual void drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const;
private:
	sf::RectangleShape bar;
	float BarLength;
};