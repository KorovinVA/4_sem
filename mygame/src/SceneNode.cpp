#include "SceneNode.h"
#include <algorithm>

SceneNode::SceneNode() :
Children(), 
Parent(nullptr)
{
}

void SceneNode::attachChild(Ptr child)
{
	child->Parent = this;
	Children.push_back(std::move(child));
}

typedef std::unique_ptr<SceneNode> Ptr;
Ptr SceneNode::detachChild(const SceneNode & node)
{
	auto found = find_if(Children.begin(), Children.end(), [&node](Ptr & p)
	{
		return p.get() == &node;
	});
	if (found == Children.end()) exit(25);
	Ptr result = std::move(*found);
	result->Parent = nullptr;
	Children.erase(found);
	return result;
}

void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform;
	for (const SceneNode* node = this; node != nullptr; node = node->Parent) {
		transform = node->getTransform() * transform;
	}
	return transform;
}

void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	drawCurrent(target, states);
	for (auto p = Children.begin(); p != Children.end(); ++p) {
		(*p)->draw(target, states);
	}
}

void SceneNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
}

void SceneNode::updateCurrent(sf::Time dt)
{
}

void SceneNode::updateChildren(sf::Time dt)
{
	for (auto p = Children.begin(); p != Children.end(); p++) {
		(*p)->update(dt);
	}
}

