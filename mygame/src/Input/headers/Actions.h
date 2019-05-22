#pragma once
#include <SFML/Graphics.hpp>
#include "../../GamePlay/headers/Warrior.h"

template<typename T>
struct Move {
	Move(float vx,  float vy);
	void operator() (SceneNode & node, sf::Time dt);

	sf::Vector2f Velocity;
};

template<typename T>
void Move<T>::operator()(SceneNode & node, sf::Time dt)
{
	T & object = static_cast<T&>(node);
	object.accelerate(Velocity);
}

template<typename T>
Move<T>::Move(float vx, float vy):
	Velocity(vx, vy)
{
}



template<typename T>
struct Attack {
	void operator() (SceneNode & node, sf::Time dt);
};

template<typename T>
void Attack<T>::operator()(SceneNode & node, sf::Time dt)
{
	T & object = static_cast<T&>(node);
	object.attack();
}



template<typename T>
struct Jump {
	void operator() (SceneNode & node, sf::Time dt);
};

template<typename T>
inline void Jump<T>::operator()(SceneNode & node, sf::Time dt)
{
	T & object = static_cast<T&>(node);
	object.jump();
}
