

#pragma once

#include "AnimSprite.h"
#include "EventHandler.h"


USING_NS_CC;


class Player :public AnimSprite
{
private:
	Point speed;

	float oldX;

public:
	Player(std::string filename, int X, int Y);
	~Player();

	void input(EventHandler *eventhandler);

	void walk();

	float getOldX();

};
