#include "Bullet.h"

Bullet::Bullet(char *p, int x, int y, int sxx, int syy, direction d, sf::RenderWindow &w, int s)
	: GameObject(p, x, y, sxx, syy, d, w)
{
	exist = false;
	speed = s;
}

Bullet::~Bullet(){}

void Bullet::move()
{
	switch (dir)
	{
	case UP:
		if (posY > 60 + sY / 2)
		{
			posY -= speed;
			sprite.setRotation(0);
		}
		else exist = false;
		break;
	case DOWN:
		if (posY < 60 + 960 - sY / 2)
		{
			posY += speed;
			sprite.setRotation(180);
		}
		else exist = false;
		break;
	case LEFT:
		if (posX > 352 + sX / 2)
		{
			posX -= speed;
			sprite.setRotation(270);
		}
		else exist = false;
		break;
	case RIGHT:
		if (posX < 352 + 1216 - sX / 2)
		{
			posX += speed;
			sprite.setRotation(90);
		}
		else exist = false;
		break;
	}
}

void Bullet::launch(int x, int y, direction d)
{
	exist = true;
	setDir(d);
	posX = x;
	posY = y;
}