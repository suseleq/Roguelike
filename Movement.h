#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Movement
{
private:
	float velocity;
	sf::Sprite& sprite;

public:
	Movement(sf::Sprite &sprite_,const float &velocity_);
	~Movement();

	void move(const sf::Vector2f &direction,const float& dt);
};

