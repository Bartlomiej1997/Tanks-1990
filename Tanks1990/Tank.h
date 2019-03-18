#pragma once
#include "GameObject.h"
#include "Bullet.h"
extern int points;
class Tank
	: public GameObject
{
	friend class Game;
protected:
	int hp;
	Bullet bullet;
	int respDelay, defaultX, defaultY;
	Tank(char *p, int x, int y, int sxx, int syy, direction d, sf::RenderWindow &w, int h);
	~Tank();
public:
	void shoot();
	void draw();
	virtual void move();
	void destroy();
	friend bool operator==(const Tank& t1, const Tank& t2);
};
