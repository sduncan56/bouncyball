

#pragma once

#include "cocos2d.h"
#include "ui\UIButton.h"


USING_NS_CC;


class GameOver : public Layer
{
private:

public:
	GameOver();
	virtual bool init();
	virtual void update(float delta);

	void retry(Event* event);
};