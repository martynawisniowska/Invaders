#include "GraphicObject.h"

GraphicObject::GraphicObject(sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
	body.setSize (size);
	body.setPosition(position);
	body.setFillColor(color);
}

GraphicObject::~GraphicObject()
{
}

void GraphicObject::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void GraphicObject::Move()
{
}

sf::Vector2f GraphicObject::Position()
{
	return body.getPosition();
}

sf::Vector2f GraphicObject::Size()
{
	return body.getSize();
}

