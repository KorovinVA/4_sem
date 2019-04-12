#pragma once
#include "../../Input/headers/Command.h"

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

enum Layer
{
	Background,
	Air,
	LayerCount
};

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;
public:
	SceneNode();

	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode & node);

	void update(sf::Time dt);
	sf::Transform getWorldTransform() const;

	void onCommand(const Command & command, sf::Time dt);
private:
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const;
	virtual int getCategory();	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);

	std::vector<Ptr> Children;
	SceneNode* Parent;
};