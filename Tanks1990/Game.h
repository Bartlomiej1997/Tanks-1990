#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Tank.h"
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "Map.h"
#include "Button.h"
#include <ctime>
#include <iostream>
#include <string>
#include <iostream>
using namespace sf;
bool operator==(const Tank& t1, const Tank& t2);
class Game
{
private:
	int points;
	bool e = false;
	RenderWindow window;
	Event event;
	Map map;
	Button *close, *start, *stop;
	sf::Vector2i mousePosition;
	Player player;
	Enemy enemy1;
	Enemy enemy2;
	Enemy enemy3;
	clock_t startC;
	sf::Font font;
	sf::Text text;
	std::string t;
public:
	Game();
	~Game();
	int run();
	void handleEvents();
	void update();
	void render();
	friend bool operator==(const Tank& t1, const Tank& t2);
	void collisionDir(Tank&, Tank&);
	template <class T, class U>
	bool collision(T &o1, U &o2);
	void collisionManager(Tank&, Tank&, Tank&, Tank&);
	void score() { points += 100; }
};