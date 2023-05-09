#include "Character.h"

void Character::initStats()
{
	this->health = 3;
}

void Character::initTexture()
{
	this->texture = new sf::Texture;
	this->texture->loadFromFile("./Textures/characterSprite.png");
	this->frame = sf::IntRect(0, 0, 32, 32);
	this->sprite.setTexture(*this->texture);
	this->sprite.setTextureRect(this->frame);
	this->sprite.setScale(3, 3);
}

void Character::initHitbox()
{
	this->hitbox = new Hitbox(this->sprite, 30, 20, 30, 65);
}

void Character::initAnimations()
{
	this->animation["IDLE"] = new Animations(this->sprite, *this->texture, 4, 70.f, sf::IntRect(0, 0, 32, 32), 0, 32);
	this->animation["RUN"] = new Animations(this->sprite, *this->texture, 8, 20.f, sf::IntRect(0, 32, 32, 32), 0, 32);
	this->animation["DAMAGE"] = new Animations(this->sprite, *this->texture, 4, 40.f, sf::IntRect(0, 64, 32, 32), 0, 32);
	this->animation["DEAD"] = new Animations(this->sprite, *this->texture, 8, 20.f, sf::IntRect(0, 96, 32, 32), 0, 32);
}

void Character::initMovement()
{
	this->movement = new Movement(this->sprite,200);
}

Character::Character()
{
	this->initStats();
	this->initTexture();
	this->initHitbox();
	this->initAnimations();
	this->initMovement();
}

Character::~Character()
{
}

void Character::update(const float& dt)
{
	if(this->isMoving)
		this->animation["RUN"]->makeAnimation(dt);
	else
		this->animation["IDLE"]->makeAnimation(dt);

	this->hitbox->uptade();
	
}


void Character::move(const float& dt,const sf::Vector2f &direction)
{
	this->isMoving = true;
	this->movement->move(direction, dt);
}
