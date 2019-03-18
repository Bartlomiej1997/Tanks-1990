#pragma once
#include "Tank.h"

class Player
	: public Tank
{
public:
	Player(char *p, int x, int y, int sxx, int syy, direction d, sf::RenderWindow &w, int h);
	~Player();
	void move(direction d);
	bool movementUP();
	bool movementDOWN();
	bool movementLEFT();
	bool movementRIGHT();
	void draw();
	bool isAlive() { return exist; }
};
