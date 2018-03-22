#pragma once
#include "Game.h"
#include <SFML\Graphics.hpp>

class Menu {
private:
	sf::RectangleShape startButton;
	sf::Text text;
	sf::Font font;

public:
	void runMenu();
};