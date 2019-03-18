#include "Menu.h"

Menu::Menu(int x, int y)
	: window(sf::VideoMode(x, y), "Menu", sf::Style::Titlebar | sf::Style::Close)
	, mousePosition(0, 0)
{
	texture.loadFromFile("assets/logo.png");
	sprite.setTexture(texture);
	sprite.setOrigin(708 / 2, 400 / 2);
	sprite.setScale(sf::Vector2f(0.3, 0.3));
	sprite.setPosition(200, 75);
	this->addButton("START", 200, 200);
	this->addButton("Leaderboard", 200, 300);
	this->addButton("EXIT", 200, 400);
}

Menu::~Menu(){}

int Menu::run()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {}
		if (event.type == sf::Event::Closed)
		{
			window.close();
			return 2;
		}

		if (event.type == sf::Event::MouseMoved)
		{
			mousePosition.x = sf::Mouse::getPosition().x - window.getPosition().x - 7;
			mousePosition.y = sf::Mouse::getPosition().y - window.getPosition().y - 31;

			for (std::vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); ++it)
				(*it)->check(mousePosition);
		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				int i = 0;
				for (std::vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); ++it)
				{
					if ((*it)->hover())
					{
						if (i == 1)
							window.setTitle("Leaderboard");
						return i;
					}
					i++;
				}
			}
		}

		for (std::vector<Button*>::iterator it = buttons.begin(); it != buttons.end(); ++it)
			(*it)->display();
		window.draw(sprite);
		window.display();
		window.clear(sf::Color(100, 100, 100, 255));
	}
}

void Menu::addButton(char* n, int x, int y, int sX, int sY)
{
	buttons.emplace_back(new Button(window, n, x, y, sX, sY));
}