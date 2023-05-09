#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>

class Menu
{
protected:
	


	float delayTime;
	bool changeOption;
	int currentOption;
	std::vector<sf::Text> text;
	sf::Font font;
	sf::Sprite background;
	sf::Texture backgroundImage;
	


	void initText();

	void updateDt(const float& dt);

public:
	Menu();
	~Menu();


	void moveUp();
	void moveDown();

	void update(const float& dt);

	void render(sf::RenderTarget& target);

	int getOption();
};

