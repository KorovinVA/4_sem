#pragma once
#include "../../World/headers/SceneNode.h"

class BarNode : public SceneNode
{
public:
	enum BarType {
		HealthBar,
		StaminaBar
	};
public:
	explicit BarNode(BarType type, float const & BarLength_);

	void resizeBar(float value);
private:
	virtual void drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const;
private:
	sf::RectangleShape bar;
	float BarLength;
};