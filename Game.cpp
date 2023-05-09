#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1200, 800), "siema");
	this->window->setFramerateLimit(60);
}

void Game::initMenu()
{
	this->menu = new Menu;
	this->state = mainMenu;
}

void Game::initGame()
{
	this->character = new Character;
}

Game::Game()
{
	this->initWindow();
	this->initMenu();
	this->initGame();
}

Game::~Game()
{
	delete this->window;
	delete this->menu;
	delete this->character;
	for (auto& i : this->bullets)
	{
		delete i;
	}
}

void Game::updateInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (this->state != game)
		{
			this->menu->moveUp();
		}
		else
		{
			this->character->move(this->dt, sf::Vector2f(0, -1));
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
	{
		if (this->state != game)
		{
			this->menu->moveDown();
		}
		else
		{
			this->character->move(this->dt, sf::Vector2f(0, 1));
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if(this->state == game)
		{
			this->character->move(this->dt, sf::Vector2f(-1, 0));
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (this->state == game)
		{
			this->character->move(this->dt, sf::Vector2f(1, 0));
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		if (this->state == game)
		{
			this->state = pauseMenu;
		}
		else if (this->state = pauseMenu)
		{
			this->state = game;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		if(this->state != game)
		{
			if (this->menu->getOption() == 0)
			{
				this->state = game;
			}
			else
			{
				this->window->close();
			}
		}
		else
		{
			
		}
	}

}

void Game::updateMousePosition()
{
	this->mousePosition = sf::Mouse::getPosition(*this->window);
}

void Game::updateCharacter()
{
	this->character->update(this->dt);
	this->character->setIsMoving(false);
}

void Game::updateEventSFML()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			this->window->close();
		}
	}
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::update()
{
	this->updateEventSFML();
	this->updateInputs();
	if (this->state != game)
	{
		this->menu->update(this->dt);
	}
	else
	{
		this->updateCharacter();
		for (auto& i : this->bullets)
		{
			i->uptade(this->dt);
		}
	}
}


void Game::render()
{
	this->window->clear(sf::Color(28, 34, 51));
	if (this->state != game)
	{
		this->menu->render(*this->window);
	}
	else
	{
		this->character->render(*this->window);
		this->wepon.render(*this->window);
		for (auto& i : this->bullets)
		{
			i->render(*this->window);
		}
	}
	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
