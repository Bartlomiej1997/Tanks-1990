#include "Tank.h"

int points;

Tank::Tank(char *p, int x, int y, int sxx, int syy, direction d, sf::RenderWindow &w, int h)
	: GameObject(p, x, y, sxx, syy, d, w)
	, bullet(Bullet("assets/bullet.png", 0, 0, 8, 8, dir, window, 3))
{
	hp = h;
	defaultX = x;
	defaultY = y;
	respDelay = 0;
}

Tank::~Tank()
{
}

void Tank::shoot()
{
	if (!bullet.launched())
	{
		int x, y;
		switch (Tank::dir)
		{
		case UP:
			x = posX;
			y = posY - sY / 2;
			break;
		case DOWN:
			x = posX;
			y = posY + sY / 2;
			break;
		case LEFT:
			x = posX - sX / 2;
			y = posY;
			break;
		case RIGHT:
			x = posX + sX / 2;
			y = posY;
			break;
		}
		bullet.launch(x, y, dir);
	}
}

void Tank::draw()
{
	GameObject::draw();

	if (bullet.launched())
	{
		bullet.move(); 
		bullet.draw();
		bullet.draw();
	}
}

void Tank::move()
{
	switch (dir)
	{
	case UP:
		if ((posY > 60 + sY / 2) && moveUP) posY--;
		sprite.setRotation(0);
		break;
	case DOWN:
		if ((posY < 60 + 960 - sY / 2) && moveDOWN) posY++;
		sprite.setRotation(180);
		break;
	case LEFT:
		if ((posX > 352 + sX / 2) && moveLEFT) posX--;
		sprite.setRotation(270);
		break;
	case RIGHT:
		if ((posX < 352 + 1216 - sX / 2) && moveRIGHT) posX++;
		sprite.setRotation(90);
		break;
	}
}

void Tank::destroy()
{
	exist = false;
	posX = 1000;
	posY = 1000;
	sprite.setPosition(posX, posY);
	respDelay = 500;

}

