

#pragma once

#include "cocos2d.h"

USING_NS_CC;

class AnimSprite : public cocos2d::Sprite
{
protected:
	bool alive;
	int velX, velY;


public:
	AnimSprite(std::string filename, int X, int Y);
	~AnimSprite();

	void walk();

	void kill();

	bool isAlive();

};