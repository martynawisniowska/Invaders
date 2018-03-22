#pragma once
#include <SFML\Graphics.hpp>

class End {

private:
	sf::Text text;
	sf::Font font;
public:
	void loose(sf::RenderWindow &window);
	void win(sf::RenderWindow &window);
};