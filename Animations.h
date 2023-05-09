#pragma once
#include "Hitbox.h"



class Animations
{
private:
	sf::Sprite& sprite;
	sf::Texture& texture;
	sf::IntRect currentFrame;
	sf::IntRect firstFrame;

	float animationTime;
	float maxFrameTime;

	int priority;
	int frameCounter;
	int maxFrame;
	int rectStep;
	
public:
	Animations(sf::Sprite &sprite_, sf::Texture &texture_, int maxFrame_, float maxTime_,
		sf::IntRect firstFrame_, int priority_, int rectStep_);
	~Animations();

	void makeAnimation(const float &dt);
	
	bool isDone() const;
	int getPriority() const;
};

