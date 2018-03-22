#pragma once
#include"GraphicObject.h"
#include <SFML\Graphics.hpp>

extern bool moovingRight;
extern bool change;

class Enemy :public GraphicObject
{
public:
	Enemy(sf::Vector2f size, sf::Vector2f position, sf::Color color);
	~Enemy();
	void Move(Enemy* enemies[55]);
	void MoveDown();
};