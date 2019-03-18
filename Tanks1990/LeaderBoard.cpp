#include "LeaderBoard.h"

LeaderBoard::LeaderBoard(sf::RenderWindow &w)
	: window(w)
	, top(new Button(window, "Leaderboard", 200, 60, 250, 50))
	, button(new Button(window, "Menu", 200, 400, 200, 50))
{
	rank.open("assets/LeaderBoard.txt", std::ios::in | std::ios::out);
	color = sf::Color(87, 32, 155, 255);
	try 
	{
		if (!font.loadFromFile("assets/Sansation.ttf")) throw 1;
	}
	catch(int)
	{
		if (!font.loadFromFile("C:/Windows/Fonts/Arial.ttf"))
			exit(-1);
	}

	for (int i = 0; i < 5; i++)
	{
		if (rank.good()) rank >> score;
		else score = 0;
		scores.push_back(score);
		data = std::to_string(score);
		tab[i].setSize(sf::Vector2f(300, 40));
		tab[i].setOrigin(sf::Vector2f(300 / 2, 40 / 2));
		tab[i].setPosition(200, 150 + 40 * i);
		tab[i].setOutlineThickness(3);
		tab[i].setOutlineColor(sf::Color::White);
		tab[i].setFillColor(color);
		text[i].setFont(font);
		text[i].setCharacterSize(30);
		text[i].setString(data);
		text[i].setOrigin(text[i].getGlobalBounds().width / 2, text[i].getGlobalBounds().height);
		text[i].setPosition(200, 150 + 40 * i);
	}
	rank.close();
}

LeaderBoard::~LeaderBoard()
{
	rank.open("assets/LeaderBoard.txt", std::ios::in | std::ios::out);
	if (rank.good())
	{
		for (int i = 0; i < 5; i++)
		{
			data = std::to_string(scores[i]);
			rank << data << std::endl;
		}
		rank.close();
	}
	delete top;
	delete button;
}

void LeaderBoard::run(int points)
{
	if (points)
	{
		scores.push_back(points);
		std::sort(scores.begin(), scores.end());
		std::reverse(scores.begin(), scores.end());
		scores.pop_back();
	}
	else points = -1;
	for (int i = 0; i < 5; i++)
	{
		if (scores[i] == points)
		{
			highlighted = i;
			points = -1;
		}
		if (highlighted > -1)
		{
			tab[highlighted].setFillColor(sf::Color::Red);
			highlighted = -1;
		}
		else
		{
			tab[i].setFillColor(color);
		}
		data = std::to_string(scores[i]);
		text[i].setString(data);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {}
		if (event.type == sf::Event::Closed)
		{
			window.close();
			exit(-1);
		}

		if (event.type == sf::Event::MouseMoved)
		{
			mousePosition.x = sf::Mouse::getPosition().x - window.getPosition().x - 7;
			mousePosition.y = sf::Mouse::getPosition().y - window.getPosition().y - 31;
			(*button).check(mousePosition);
		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if ((*button).hover())
				{
					window.setTitle("Menu");
					return;
				}
			}
		}

		for (int i = 0; i < 5; i++)
		{
			window.draw(tab[i]);
			text[i].setOrigin(text[i].getGlobalBounds().width / 2, text[i].getGlobalBounds().height);
			window.draw(text[i]);
		}
		(*top).display();
		(*button).display();	
		window.display();
		window.clear(sf::Color(100, 100, 100, 255));
	}
}
