#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <vector>

class Menu
{
private:
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2i mousePosition;
	std::vector < Button* > buttons;
	void addButton(char* n, int x, int y, int sX=200, int sY=50);
public:
	Menu(int x = 400, int y = 500);
	~Menu();
	int run();
	sf::RenderWindow & getWindow() { return window; }
};