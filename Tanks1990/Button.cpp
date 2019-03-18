#include "Button.h"

Button::Button(sf::RenderWindow &w, char* s, int x, int y, int sX, int sY)
	: window(w), name(s), posX(x), posY(y), sizeX(sX), sizeY(sY)
{
	ifHover = false;
	color = sf::Color(87, 32, 155, 255);

	shape.setSize(sf::Vector2f(sizeX, sizeY));
	shape.setOrigin(sf::Vector2f(sizeX / 2, sizeY / 2));
	shape.setPosition(posX, posY);
	shape.setOutlineThickness(3);
	shape.setOutlineColor(sf::Color::White);
	shape.setFillColor(color);

	if (!font.loadFromFile("assets/Sansation.ttf"))
	{
		if (!font.loadFromFile("C:/Windows/Fonts/Arial.ttf"))
			exit(-1);
	}

	text.setFont(font);
	text.setCharacterSize(sizeY / 2);
	text.setString(name);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height);
	text.setPosition(posX, posY);
}

Button::~Button(){}

void Button::display()
{
	window.draw(shape);
	window.draw(text);
}

void Button::check(sf::Vector2i pos)
{
	if (pos.x > posX - sizeX / 2 && pos.x < posX + sizeX / 2 && pos.y > posY - sizeY / 2 && pos.y < posY + sizeY / 2)
	{
		color = sf::Color(187, 132, 255, 255);
		shape.setFillColor(color);
		ifHover = true;
	}
	else
	{
		color = sf::Color(87, 32, 155, 255);
		shape.setFillColor(color);
		ifHover = false;
	}
}