

#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Bullet : public cocos2d::Sprite
{
private:

public:
	Bullet(int x, int y, int xDir);

	void clean(float f);
};