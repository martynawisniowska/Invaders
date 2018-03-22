#pragma once
#include <SFML\Graphics.hpp>
#include "GraphicObject.h"

class Player : public GraphicObject
{
public:
	Player(sf::Vector2f pSize, sf::Vector2f pPosition, sf::Color color);
	~Player();

	void Move();
	sf::Vector2f getPos();
};

