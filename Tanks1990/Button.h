#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Button
{
private:
	int posX, posY, sizeX, sizeY;
	char* name;

	sf::RenderWindow &window;
	sf::RectangleShape shape;
	sf::Font font;
	sf::Text text;
	sf::Color color;
	bool ifHover;

public:
	Button(sf::RenderWindow &w, char* s, int x, int y, int sX, int sY);
	~Button();

	void display();
	void check(sf::Vector2i mousePos);
	bool hover() { return ifHover; }
};
