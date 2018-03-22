#include "Game.h"
#include <iostream>

bool moovingRight = true;
bool change = false;

void Game::RunGame(sf::RenderWindow& window)
{
	Player* player = new Player(sf::Vector2f(50, 25), sf::Vector2f(window.getSize().x/2 -25, 560), sf::Color::Cyan);
	Bullet* bullet = nullptr;
	EnemyBullet* enemyBullet = nullptr;
	int score = 0;
	int deadEnemies = 0;


	End endgame;

	srand(time(NULL));
	int shootingOne;

	sf::Font font;
	font.loadFromFile("Mecha.ttf");
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(24);
	scoreText.setPosition(sf::Vector2f(20, 5));


	bool isShooting = false;

	window.setFramerateLimit(60); 
	

	Wall* walls[18];
	for (int i = 0; i < 18; i++)
	{
		walls[i] = new Wall(sf::Vector2f(40, 30), sf::Vector2f(i/2*40+i/6*180 +40, i % 2 * 30 + 400), sf::Color::Green);
	}

	Enemy* enemies[55];
	for (int i = 0; i < 55; i++) {
		enemies[i] = new Enemy(sf::Vector2f(40, 20), sf::Vector2f(i % 11 * 50 + 10, i / 11 * 30 + 50), sf::Color::Red);
	}

	std::vector <GraphicObject*> objects;
	objects.push_back(player);
	objects.push_back(bullet);
	objects.push_back(enemyBullet);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed )
				window.close();
		}

		objects.erase(objects.begin(), objects.end());

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bullet == nullptr) {
			isShooting = true;
		}
		
		if (isShooting)
		{
			bullet=new Bullet(sf::Vector2f(5.0f, 10.0f), sf::Vector2f(player->getPos().x+25,player->getPos().y), sf::Color::White);
			isShooting = false;
		}

		if (bullet != nullptr) {
			if (bullet->isOutUp()) {
				delete bullet;
				bullet = nullptr;
			}
		}

		if (enemyBullet == nullptr) {
			shootingOne = rand() % 55;
			while (enemies[shootingOne] == nullptr) {
				shootingOne = rand() % 55;
			}
			enemyBullet = new EnemyBullet(sf::Vector2f(5.0f, 10.0f), enemies[shootingOne]->Position(), sf::Color::Magenta);
		}

		if (enemyBullet != nullptr) {
			if (enemyBullet->isOutDown()) {
				delete enemyBullet;
				enemyBullet = nullptr;
			}
		}

		window.clear();

		for (int i = 0; i < 55; i++) { 
			if (enemies[i] != nullptr) {
				enemies[i]->Move(enemies);
				enemies[i]->Draw(window);
				if (enemies[i]->Position().y >= window.getSize().y) endgame.loose(window);
				if (bullet != nullptr && bullet->isCollision(*enemies[i])) {
					delete bullet;
					delete enemies[i];
					bullet = nullptr;
					enemies[i] = nullptr;
					score += 10;
					deadEnemies++;
				}
			}
		}

		for (int i = 0; i < 55; i++)
		{
			if (enemies[i] != nullptr) {
				if (enemies[i]->Position().x >= 800 - enemies[i]->Size().x)
				{
					moovingRight = false;
					change = true;
				}
				else if (enemies[i]->Position().x <= 0) {
					moovingRight = true;
					change = true;
				}
			}
		}

		if (deadEnemies == sizeof(enemies) / sizeof(*enemies)) endgame.win(window);

		for (int i = 0; i < 18; i++) {
			if (walls[i] != nullptr) {
				walls[i]->Draw(window);
				if (enemyBullet != nullptr && enemyBullet->isCollision(*walls[i])) {
					delete enemyBullet;
					enemyBullet = nullptr;
				}
				if (bullet != nullptr && bullet->isCollision(*walls[i])) {
					delete bullet;
					delete walls[i];
					bullet = nullptr;
					walls[i] = nullptr;
				}
			}
		}

		if (enemyBullet != nullptr && enemyBullet->isCollision(*player)) {
			delete enemyBullet;
			delete player;
			enemyBullet = nullptr;
			player = nullptr;
			endgame.loose(window);
		}

		objects.push_back(player);
		objects.push_back(bullet);
		objects.push_back(enemyBullet);

		for (int i=0;i<objects.size();i++)
		{
			if (objects[i] != nullptr) {
				objects[i]->Move();
				objects[i]->Draw(window);
			}
		}

		std::string scoreString = "Score : ";
		scoreString += std::to_string(score);
		scoreText.setString(scoreString);

		window.draw(scoreText);
		window.display();
	}

	objects.erase(objects.begin(), objects.end());
	if (player != nullptr) {
		delete player;
		player = nullptr;
	}
}