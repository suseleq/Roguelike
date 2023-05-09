#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f& direction_, const sf::Vector2f& position, const bool& enemy_)
	: direction(direction_), enemy(enemy_)
{
	this->texture = new sf::Texture;
	this->texture->loadFromFile("./Textures/bullets.png");
	this->sprite.setTexture(*this->texture);
	this->sprite.setPosition(100, 100);
	this->movement = new Movement(this->sprite, 100);
	
	this->hitbox = new Hitbox(this->sprite, 6, 6, 20, 20);
}

Bullet::~Bullet()
{
	delete this->movement;
	delete this->hitbox;
	delete this->texture;
}

void Bullet::uptade(const float& dt)
{
	this->movement->move(this->direction, dt);
	this->hitbox->uptade();
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	this->hitbox->render(target);
}
