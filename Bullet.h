#pragma once
#include "Movement.h"
#include "Hitbox.h"
class Bullet
{
private:
	Hitbox* hitbox;
	Movement* movement;
	sf::Sprite sprite;
	sf::Vector2f direction;
	sf::Texture* texture;
	bool enemy;

public:
	Bullet(const sf::Vector2f &direction_, const sf::Vector2f& position, const bool &enemy_);
	~Bullet();

	void uptade(const float &dt);
	void render(sf::RenderTarget& target);

};

