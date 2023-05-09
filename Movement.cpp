#include "Movement.h"

Movement::Movement(sf::Sprite& sprite_, const float& velocity_)
	: sprite(sprite_), velocity(velocity_)
{
}

Movement::~Movement()
{
}

void Movement::move(const sf::Vector2f& direction, const float& dt)
{
	sprite.move(direction.x * dt * velocity, direction.y * dt * velocity);
}
