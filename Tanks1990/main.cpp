#include <SFML/Window.hpp>
#include <vector>
#include <exception>
#include "Menu.h"
#include "Game.h"
#include "LeaderBoard.h"
int main()
{
	int points;
	Menu menu;
	LeaderBoard lb(menu.getWindow());
	while (1)
	{
		points = 0;
		switch (menu.run())
		{
		case 0:
		{
			Game game;
			points = game.run();
		}
		case 1:
			lb.run(points);
			break;
		case 2:
			return 0;
		}
	}
}