#pragma once
#include "GraphicObject.h"

class Wall : public GraphicObject
{
public:
	Wall(sf::Vector2f size, sf::Vector2f position, sf::Color color);
	~Wall();
	
};