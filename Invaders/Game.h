#pragma once
#include "Player.h"
#include "enemy.h"
#include "wall.h"
#include "End.h"
#include "EnemyBullet.h"
#include <SFML\Graphics.hpp>

class Game
{
public:
	void RunGame(sf::RenderWindow& window);
};