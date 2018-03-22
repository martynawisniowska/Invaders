#include "enemy.h"

Enemy::Enemy(sf::Vector2f size, sf::Vector2f position, sf::Color color) : GraphicObject(size, position, color)
{
}

Enemy::~Enemy()
{
}

void Enemy::Move(Enemy* enemies[55])
{
	if (moovingRight) {
		if /*(body.getPosition().x >= 800 - body.getSize().x)*/(change)
		{
			//moovingRight = false;
			change = false;
			for (int i = 0; i < 55; i++) if(enemies[i]!=nullptr) enemies[i]->MoveDown();
		}
		/*else */body.move(1.5f , 0.0f );
	}
	else {
		if /*(body.getPosition().x <= 0)*/(change)
		{
			//moovingRight = true;
			change = false;
			for (int i = 0; i < 55; i++)  if (enemies[i] != nullptr) enemies[i]->MoveDown();
		}
		/*else*/ body.move(-1.5f , 0.0f);
	}
}

void Enemy::MoveDown()
{
	body.move(0.0f, 5.0f);
}
