

#pragma once



#include "AnimSprite.h"
#include "Bullet.h"

#include "SimpleAudioEngine.h"


class Enemy : public AnimSprite
{
private:
	std::vector<Bullet*> bullets;
	Scheduler* scheduler;

public:
	Enemy(std::string filename, int X, int Y);
	~Enemy();

	void shoot(float f);
};