#include "Menu.h"

Menu::Menu()
{
	this->delayTime = 0;
	this->changeOption = true;
	this->currentOption = 0;
	this->font.loadFromFile("./fonts/PixellettersFull.ttf");
	this->backgroundImage.loadFromFile("./Textures/background.png");
	this->background.setTexture(this->backgroundImage);
	this->initText();
}

Menu::~Menu()
{
}

void Menu::initText()
{
	float x{ 100.f };
	float y{ 100.f };
	this->text = std::vector<sf::Text>(2);
	for (auto& i : text)
	{
		i.setFont(this->font);
		i.setFillColor(sf::Color::White);
		i.setCharacterSize(100);
		i.setPosition(x, y);
		y += 200;
	}
	this->text[0].setFillColor(sf::Color::Red);
	this->text[0].setString("Play");
	this->text[1].setString("Quit");
}



void Menu::updateDt(const float& dt)
{
	if (this->delayTime <= 300.f)
		this->delayTime += 100 * dt;
	else
		this->changeOption = true;
}

void Menu::moveUp()
{
	if (this->currentOption > 0)
	{
		this->text[this->currentOption].setFillColor(sf::Color::White);
		this->currentOption--;
		this->text[currentOption].setFillColor(sf::Color::Red);
		this->changeOption = false;
	}
}

void Menu::moveDown()
{
	if (this->currentOption < this->text.size() - 1)
	{
		this->text[this->currentOption].setFillColor(sf::Color::White);
		this->currentOption++;
		this->text[currentOption].setFillColor(sf::Color::Red);
		this->changeOption = false;
	}
}

void Menu::update(const float& dt)
{
	this->updateDt(dt);
}

void Menu::render(sf::RenderTarget& target)
{
	target.draw(this->background);
	for (auto& i : this->text)
	{
		target.draw(i);
	}
}

int Menu::getOption()
{
	return this->currentOption;
}




