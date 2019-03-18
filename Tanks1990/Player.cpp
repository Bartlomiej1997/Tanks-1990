#include "Player.h"



Player::Player(char *p, int x, int y, int sxx, int syy, direction d, sf::RenderWindow &w, int h)
	: Tank(p, x, y, sxx, syy, d, w, h)
{

}

Player::~Player() {}

void Player::move(direction d)
{
	dir = d;
	Tank::move();
	sprite.setPosition(posX, posY);
}

bool Player::movementUP()
{
	return moveUP;
}
bool Player::movementDOWN()
{
	return moveDOWN;
}
bool Player::movementLEFT()
{
	return moveLEFT;
}
bool Player::movementRIGHT()
{
	return moveRIGHT;
}

void Player::draw()
{
	Tank::draw();
	if (!exist)
	{
		if (!(respDelay--))
		{
			posX = defaultX;
			posY = defaultY;
			exist = true;
		}
	}
}
