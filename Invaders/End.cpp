#include "End.h"

void End::loose(sf::RenderWindow &window)
{
	font.loadFromFile("Mecha.ttf");
	text.setFont(font);
	text.setCharacterSize(52);
	text.setPosition(window.getSize().x / 2 - 75, window.getSize().y / 2 - 50);
	text.setString("You loose!");

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				window.close();
		}

		window.clear();
		window.draw(text);
		window.display();
	}
}

void End::win(sf::RenderWindow &window)
{
	font.loadFromFile("Mecha.ttf");
	text.setFont(font);
	text.setCharacterSize(52);
	text.setPosition(sf::Vector2f(window.getSize().x / 2 - 50, window.getSize().y / 2 - 50));
	text.setString("You win!");

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				window.close();
		}

		window.clear();
		window.draw(text);
		window.display();
	}
}
