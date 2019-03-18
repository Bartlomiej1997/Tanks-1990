#include "Game.h"

Game::Game()
	: window(sf::VideoMode(1920, 1080, 32), "Tanks")
	, map(Map(window, 1920 / 2, 1080 / 2, 19 * 64, 15 * 64, sf::Color::Black))
	, close(new Button(window, "Exit", 170, 500, 250, 50)), start(new Button(window, "START", 170, 400, 250, 50)), stop(new Button(window, "STOP", 170, 400, 250, 50))
	, player(Player("assets/player2.png", 32 + map.getX() + 8 * 64, 32 + map.getY() + 14 * 64, 64, 64, direction::UP, window, 1))
	, enemy1(Enemy("assets/black.png", 32 + map.getX(), 32 + map.getY(), 64, 64, direction::DOWN, window, 1))
	, enemy2(Enemy("assets/black.png", 32 + map.getX() + 9 * 64, 32 + map.getY(), 64, 64, direction::DOWN, window, 1))
	, enemy3(Enemy("assets/black.png", 32 + map.getX() + 18 * 64, 32 + map.getY(), 64, 64, direction::DOWN, window, 1))
{
	window.setPosition(sf::Vector2i(0, 0));

	if (!font.loadFromFile("assets/Sansation.ttf"))
	{
		if (!font.loadFromFile("C:/Windows/Fonts/Arial.ttf"))
			exit(-1);
	}

	text.setFont(font);
	points = 0;
	text.setCharacterSize(50);

	window.setPosition(Vector2i(0, 0));
	enemy1.setColor(sf::Color::Blue);
	enemy2.setColor(sf::Color::Red);
	enemy3.setColor(sf::Color::Green);
}

Game::~Game()
{
	delete close;
	delete start;
	delete stop;
}

int Game::run()
{
	while (window.isOpen())
	{
		if (!player.isAlive())
		{
			Button b(window, "GAME OVER", 960, 540, 1600, 400);
			b.display();
			window.display();
			sleep(sf::milliseconds(3000));
			break;
		}
		startC = clock();
		handleEvents();
		update();
		collisionManager(player, enemy1, enemy2, enemy3);
		render();
		if (clock() - startC < 3)
			sleep(sf::milliseconds(3 - (clock() - startC)));
	}
	return points;
}

void Game::handleEvents()
{
	while (window.pollEvent(event)) {}

	if (event.type == Event::Closed)
	{
		sleep(sf::milliseconds(1000));
		window.close();
	}

	if (event.type == sf::Event::MouseMoved)
	{
		mousePosition.x = sf::Mouse::getPosition().x - window.getPosition().x - 7;
		mousePosition.y = sf::Mouse::getPosition().y - window.getPosition().y - 31;
		(*close).check(mousePosition);
		(*start).check(mousePosition);
		(*stop).check(mousePosition);
	}
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if ((*close).hover())
			{
				sleep(sf::milliseconds(1000));
				window.close();
			}
			if (e)
			{
				if ((*stop).hover())
				{
					sleep(sf::milliseconds(100));
					e = !(e);
				}
			}
			else
			{
				if ((*start).hover())
				{
					sleep(sf::milliseconds(100));
					e = !(e);
				}
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
	{
		e = !(e);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		player.shoot();
	}

	if (Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (player.movementUP()) player.move(direction::UP);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (player.movementDOWN()) player.move(direction::DOWN);
	}
	else if (Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (player.movementLEFT()) player.move(direction::LEFT);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (player.movementRIGHT()) player.move(direction::RIGHT);
	}
}

void Game::update()
{
	std::string s;
	t = "Points: ";
	s = std::to_string(points);
	t += s;

	map.draw();
	(*close).display();
	if (e)(*stop).display();
	else (*start).display();
	if (e) enemy1.move();
	if (e) enemy2.move();
	if (e) enemy3.move();
	player.draw();
	enemy1.draw();
	enemy2.draw();
	enemy3.draw();
	text.setString(t);
	window.draw(text);
}

void Game::render()
{
	window.display();
	window.clear(Color(100, 100, 100, 255));
}

bool operator==(Tank& t1, Tank& t2)
{
	if (t1.sprite.getGlobalBounds().intersects(t2.sprite.getGlobalBounds()))
		{
			return true;
		}
	return false;
}

template <class T, class U>
bool Game::collision(T &o1, U &o2)
{
	if (o1.sprite.getGlobalBounds().intersects(o2.sprite.getGlobalBounds()) && o1.exist && o2.exist)
	{
		o1.destroy();
		o2.destroy();
		return true;
	}
	return false;
}

void Game::collisionDir(Tank& t1, Tank& t2)
{
	if (t1.posX > t2.posX)	
	{
		if (t1.dir == LEFT) t1.moveLEFT = false;
		if (t2.dir == RIGHT) t2.moveRIGHT = false;
	}
	if (t1.posX < t2.posX)	
	{
		if (t1.dir == RIGHT) t1.moveRIGHT = false;
		if (t2.dir == LEFT) t2.moveLEFT = false;
	}
	if (t1.posY > t2.posY)	
	{
		if (t1.dir == UP) t1.moveUP = false;
		if (t2.dir == DOWN) t2.moveDOWN = false;
	}
	if (t1.posY < t2.posY)	
	{
		if (t1.dir == DOWN) t1.moveDOWN = false;
		if (t2.dir == UP) t2.moveUP = false;
	}
}

void Game::collisionManager(Tank& t1, Tank& t2, Tank& t3, Tank& t4)
{
	t1.moveUP = true;		t1.moveDOWN = true;		t1.moveLEFT = true;		t1.moveRIGHT = true;
	t2.moveUP = true;		t2.moveDOWN = true;		t2.moveLEFT = true;		t2.moveRIGHT = true;
	t3.moveUP = true;		t3.moveDOWN = true;		t3.moveLEFT = true;		t3.moveRIGHT = true;
	t4.moveUP = true;		t4.moveDOWN = true;		t4.moveLEFT = true;		t4.moveRIGHT = true;


	if (t1==t2) collisionDir(t1, t2);
	if (t1==t3) collisionDir(t1, t3);
	if (t1==t4) collisionDir(t1, t4);

	if (t2==t3) collisionDir(t2, t3);
	if (t2==t4) collisionDir(t2, t4);

	if (t3==t4) collisionDir(t3, t4);


	if (collision<Tank, Bullet>(t2, t1.bullet)) score();
	if (collision<Tank, Bullet>(t3, t1.bullet)) score();
	if (collision<Tank, Bullet>(t4, t1.bullet)) score();

	collision<Tank, Bullet>(t1, t2.bullet);
	collision<Tank, Bullet>(t1, t3.bullet);
	collision<Tank, Bullet>(t1, t4.bullet);


	collision<Bullet, Bullet>(t1.bullet, t2.bullet);
	collision<Bullet, Bullet>(t1.bullet, t3.bullet);
	collision<Bullet, Bullet>(t1.bullet, t4.bullet);

}
