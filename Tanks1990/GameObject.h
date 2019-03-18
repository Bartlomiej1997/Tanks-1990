#pragma once
#include <SFML/Graphics.hpp>
enum direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class GameObject
{
	friend class Game;
protected:
	int posX, posY, sX, sY;
	char *path;
	bool exist;
	bool moveUP;
	bool moveDOWN;
	bool moveLEFT;
	bool moveRIGHT;
	direction dir;
	sf::Texture texture;
	sf::RenderWindow &window;

public:
	GameObject(char *p, int x, int y, int sxx, int syy, direction d, sf::RenderWindow &w); 
	~GameObject();
	sf::Sprite sprite;
	void setDir (direction d){ dir = d; }
	virtual void move()=0;
	void draw();
	void destroy(){ exist = false; }
};