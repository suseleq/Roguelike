#pragma once
#include "Hitbox.h"
#include "Animations.h"
#include "Movement.h"
#include <map>


class Entities
{
protected:
	sf::Sprite sprite;
	sf::Texture* texture;
	Hitbox *hitbox;
	Movement* movement;
	sf::IntRect frame;

	std::map < std::string, Animations* > animation;

	
	int health;
	bool isMoving;
	
	virtual void initStats() = 0;
	virtual void initTexture() = 0;
	virtual void initHitbox() = 0;
	virtual void initMovement() = 0;
	virtual void initAnimations() = 0;

public:
	Entities();
	~Entities();
	
	virtual void move(const float& dt,const sf::Vector2f &direction) = 0;
	sf::Vector2f getPosition();
	void setIsMoving(bool moving);
	bool getIsMoving();

	virtual void update(const float& dt) = 0;
	void render(sf::RenderTarget &target);
};

