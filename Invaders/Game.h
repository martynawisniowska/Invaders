#pragma once
#include "Player.h"
#include "bullet.h"
#include "enemy.h"
#include "wall.h"
#include "End.h"
#include <SFML\Graphics.hpp>

class Game
{
public:
	void RunGame(sf::RenderWindow& window);
};