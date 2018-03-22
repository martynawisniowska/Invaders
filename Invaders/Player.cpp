#include "Player.h"



Player::Player(sf::Vector2f size, sf::Vector2f position, sf::Color color) : GraphicObject(size, position,color)
{
}

Player::~Player()
{
}

void Player::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && body.getPosition().x>0)
		body.move(-3.0f, 0.0f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && body.getPosition().x + body.getSize().x<800)
		body.move(3.0f, 0.0f);
}

sf::Vector2f Player::getPos()
{
	return sf::Vector2f(body.getPosition().x, body.getPosition().y);
}
