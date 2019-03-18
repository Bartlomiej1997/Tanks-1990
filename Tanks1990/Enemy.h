#pragma once
#include "Tank.h"

class Enemy
	: public Tank
{
private:
	sf::Color color;
	int i, d;
	direction dir;
	void AI();
	int prevX, prevY;
public:
	Enemy(char *p, int x, int y, int sxx, int syy, direction d, sf::RenderWindow &w, int h);
	~Enemy();
	void move();
	void setColor(sf::Color c);
};