#include "Map.h"

Map::Map(sf::RenderWindow &w, int x, int y, int sx, int sy, sf::Color c)
	: shape(sf::Vector2f(sx, sy))
	, window(w), posX(x), posY(y), sizeX(sx), sizeY(sy), color(c)
{
	shape.setOrigin(sizeX / 2, sizeY / 2);
	shape.setPosition(posX, posY);
	shape.setFillColor(color);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(5);
}

Map::~Map(){}
