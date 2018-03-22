#include "Menu.h"

void Menu::runMenu()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Invaders", sf::Style::Close | sf::Style::Titlebar);
	font.loadFromFile("Mecha.ttf");
	text.setFont(font);
	text.setString("Start");
	text.setCharacterSize(52);
	startButton.setSize(sf::Vector2f(200, 100));
	startButton.setFillColor(sf::Color::Red);
	startButton.setOrigin(sf::Vector2f(startButton.getSize().x / 2, startButton.getSize().y / 2));
	startButton.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	text.setPosition(sf::Vector2f(startButton.getPosition().x - 50, startButton.getPosition().y - 35));

	Game game;

	sf::Mouse mouse;
	sf::Vector2i mousePos;

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				window.close();
		}

		window.clear();
		window.draw(startButton);
		window.draw(text);
		window.display();

		if (mouse.isButtonPressed(sf::Mouse::Button::Left))
		{
			mousePos = mouse.getPosition(window);
			if (mousePos.x <= startButton.getPosition().x + startButton.getSize().x / 2 &&
				mousePos.x >= startButton.getPosition().x - startButton.getSize().x / 2 &&
				mousePos.y <= startButton.getPosition().y + startButton.getSize().y / 2 &&
				mousePos.y >= startButton.getPosition().y - startButton.getSize().y / 2) {
				game.RunGame(window);
			}
		}
	}
}
