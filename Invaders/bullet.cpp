#include "bullet.h"
#include <iostream>

Bullet::Bullet(sf::Vector2f size, sf::Vector2f position, sf::Color color) : GraphicObject(size, position, color)
{
}

Bullet::~Bullet()
{
}


void Bullet::Move()
{
	body.move(0, -7.0f);
}


bool Bullet::isOutUp()
{
	float posY = body.getPosition().y;
	if (posY >= -(body.getSize().y)) return false;
	else return true;
}

bool Bullet::isOutDown()
{
	float posY = body.getPosition().y;
	if (posY <= 600) return false;
	else return true;
}

bool Bullet::isCollision(GraphicObject obj)
{
	float enPosX = obj.Position().x;
	float enPosY = obj.Position().y;

	float myPosX = body.getPosition().x;
	float myPosY = body.getPosition().y;

	float enSizeX = obj.Size().x;
	float enSizeY = obj.Size().y;

	float mySizeX = body.getSize().x;
	float mySizeY = body.getSize().y;

	if (myPosX >= enPosX - mySizeX && myPosX <= enPosX + enSizeX && (myPosY <= enPosY + enSizeY && myPosY+mySizeY>=enPosY)) return true;
	return false;
}
