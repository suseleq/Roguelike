#pragma once
#include "Entities.h"

class Character : public Entities
{
private:

	void initStats();
	void initTexture();
	void initHitbox();
	void initAnimations();
	void initMovement();

public:

	Character();
	~Character();

	void move(const float& dt,const sf::Vector2f &direction);
	void update(const float &dt);
};

