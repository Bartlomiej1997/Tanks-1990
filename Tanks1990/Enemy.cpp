#include "Enemy.h"



Enemy::Enemy(char *p, int x, int y, int sxx, int syy, direction d, sf::RenderWindow &w, int h)
	: Tank(p, x, y, sxx, syy, d, w, h)
{
	i = 0;
}

Enemy::~Enemy() {}

void Enemy::move()
{
	prevX = posX;
	prevY = posY;
	AI();
	Tank::move();
	if (prevX == posX && prevY == posY) i = 0; 
}

void Enemy::AI()
{
	if (exist)
	{
		if (!(i--))
		{
			i = rand() % 300 + 200;
			d = rand() % 4;
			switch (d)
			{
			case 0:
				setDir(direction::UP);
				break;
			case 1:
				setDir(direction::DOWN);
				break;
			case 2:
				setDir(direction::LEFT);
				break;
			case 3:
				setDir(direction::RIGHT);
				break;
			}
		}

		if (!(i % (100 * d + 100))) shoot();
	}
	else
	{
		if (!(respDelay--))
		{
			posX = defaultX;
			posY = defaultY;
			exist = true;
			points += 100;
		}
	}
}

void Enemy::setColor(sf::Color c)
{
	sprite.setColor(c);
}

