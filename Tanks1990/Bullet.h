#pragma once
#include "GameObject.h"
class Bullet
	: public GameObject
{
	friend class Game;
private:
	int speed;

public:
	Bullet(char *p, int x, int y, int sxx, int syy, direction d, sf::RenderWindow &w, int s = 3);
	~Bullet();
	void launch(int x, int y, direction d);
	virtual void move();
	bool launched(){ return exist; }
};