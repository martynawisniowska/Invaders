#pragma once
#include "GraphicObject.h"
#include <SFML\Graphics.hpp>

class Bullet : public GraphicObject
{
public:
	Bullet(sf::Vector2f size, sf::Vector2f position, sf::Color color);
	~Bullet();
	void Move();
	bool isOutUp();
	bool isOutDown();
	bool isCollision(GraphicObject obj);
};