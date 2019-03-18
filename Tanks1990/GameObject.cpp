#include "GameObject.h"

GameObject::GameObject(char *p, int x, int y, int sxx, int syy, direction d, sf::RenderWindow &w)
	:window(w), posX(x), posY(y), sX(sxx), sY(syy), dir(d), path(p)
{
	exist = true;
	moveUP = true;
	moveDOWN = true;
	moveLEFT = true;
	moveRIGHT = true;
	if (!texture.loadFromFile(path))
	{
		exit(-1);
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sxx / 2, syy / 2);
}

GameObject::~GameObject(){}

void GameObject::draw()
{
	sprite.setPosition(posX, posY);
	if (exist) window.draw(sprite);
}