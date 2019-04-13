#pragma once

#include <SFML/Graphics.hpp>
#include "../../Resources/ResourceHolder.h"
#include "DataTables.h"

class Animation {
public:
	Animation();

	void getTextures(WarriorData * data, TextureHolder * textures);
public:
	enum State
	{
		Idle,
		Run,
		Attack,
		Die
	};

	enum Orientation
	{
		Left,
		Right
	};
protected:
	void createSpriteOrientation(Orientation orientation);
	void update(State state);
	bool isAttacking();
	void resetAttackValue();

	sf::Sprite Sprite;

	std::pair<std::vector<sf::Texture>, size_t> Idle_;
	std::pair<std::vector<sf::Texture>, size_t> Run_;
	std::pair<std::vector<sf::Texture>, size_t> Attack_;
	std::pair<std::vector<sf::Texture>, size_t> Die_;
private:
	void updateIdle();
	void updateRun();
	void updateAttack();
	void updateDie();

	void getIdleText(TextureHolder * textures, WarriorData * data);
	void getRunText(TextureHolder * textures, WarriorData * data);
	void getAttackText(TextureHolder * textures, WarriorData * data);
	void getDieText(TextureHolder * textures, WarriorData * data);
private:
	sf::Clock idleTimeDelay;
	sf::Clock runTimeDelay;
	sf::Clock attackTimeDelay;
	sf::Clock dieTimeDelay;

	float AttackFrequency;
	size_t AttackTextureNumber;
	bool NowAttacking;

	size_t CurrentIdleText;
	size_t CurrentRunText;
	size_t CurrentAttackText;
	size_t CurrentDieText;
};