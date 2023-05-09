#pragma once
#include "Bullet.h"

class Weapon
{
private:
	sf::CircleShape orbit;
	sf::Sprite sprite;
	sf::Texture* texture;
	sf::IntRect weaponRect;

	float maxDelay;
	float delayTime;

public:
	Weapon(float maxDelay_);
	~Weapon();

	void uptade(const float& dt);
	void render(sf::RenderTarget &target);
};
