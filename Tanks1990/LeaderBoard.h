#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Button.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class LeaderBoard
{
private:
	sf::RenderWindow &window;
	sf::RectangleShape tab[5];
	sf::Text text[5];
	sf::Color color;
	sf::Font font;
	std::fstream rank;
	std::vector <int> scores;
	int score;
	int highlighted = -1;
	std::string data;
	Button *top;
	Button *button;
	sf::Vector2i mousePosition;
public:
	LeaderBoard(sf::RenderWindow &w);
	~LeaderBoard();
	void run(int points);
};

