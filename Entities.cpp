#include "Entities.h"

Entities::Entities()
{
	this->health = 0;
	this->hitbox = nullptr;
	this->isMoving = false;
	this->texture = nullptr;
	this->movement = 0;
}

Entities::~Entities()
{
	delete this->hitbox;
	delete this->texture;
	for (auto &i : this->animation) 
	{
		delete i.second;
	}
	delete this->movement;
}

sf::Vector2f Entities::getPosition()
{
	return this->getPosition();
}

void Entities::setIsMoving(bool moving)
{
	this->isMoving = moving;
}

bool Entities::getIsMoving()
{
	return this->isMoving;
}

void Entities::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	this->hitbox->render(target);
}

