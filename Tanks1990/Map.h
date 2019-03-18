#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Map
{
private:
	int posX, posY, sizeX, sizeY;
	sf::RenderWindow &window;
	sf::Color color;
	sf::RectangleShape shape;
	sf::Font font;
public:
	Map(sf::RenderWindow &w, int x, int y, int sx, int sy, sf::Color c);
	~Map();
	void draw(){ window.draw(shape); }
	int getX() { return posX - sizeX / 2; }
	int getY() { return posY - sizeY / 2; }
};


