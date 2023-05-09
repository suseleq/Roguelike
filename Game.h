#pragma once
#include "Menu.h"
#include "Entities.h"
#include "Character.h"
#include "Bullet.h"
#include "Weapon.h"

class Game
{
private:
	enum GameState
	{
		mainMenu,
		pauseMenu,
		game
	};

	GameState state;

	sf::RenderWindow* window;
	sf::Event event;

	Menu* menu;

	Entities* character;
	std::vector<Bullet*> bullets;

	Weapon wepon;

	sf::Vector2i mousePosition;

	sf::Clock dtClock;
	float dt;

	void initWindow();
	void initMenu();
	void initGame();

	void updateInputs();
	void updateMousePosition();
	void updateCharacter();
	void updateEventSFML();
	void updateDt();
	void update();
	void render();

public:

	Game();
	~Game();

	void run();

};

