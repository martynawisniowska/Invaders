#pragma once
#include <SFML\Graphics.hpp>

class GraphicObject
{
public:
	GraphicObject(sf::Vector2f size, sf::Vector2f position, sf::Color color);
	~GraphicObject();

	void Draw(sf::RenderWindow& window);
	virtual void Move();
	sf::Vector2f Position();
	sf::Vector2f Size();


protected:
	sf::RectangleShape body;
};