#include "Weapon.h"

Weapon::Weapon(float maxDelay_) : maxDelay(maxDelay_)
{
	this->delayTime = 0.f;
	this->texture = new sf::Texture;
	this->texture->loadFromFile("./Textures/pistols.png");
	this->weaponRect = sf::IntRect(32, 0, 16, 16);
	this->sprite.setTexture(*this->texture);
	this->sprite.setTextureRect(this->weaponRect);
	this->sprite.setScale(3, 3);
	this->sprite.setPosition(100, 100);
}

Weapon::~Weapon()
{
	delete this->texture;
}

void Weapon::uptade(const float& dt)
{
	
}

void Weapon::render(sf::RenderTarget &target)
{
	target.draw(this->sprite);
}
