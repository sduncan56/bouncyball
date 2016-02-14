


#pragma once

#include "cocos2d.h"

#include "SimpleAudioEngine.h"


USING_NS_CC;

class Ball : public cocos2d::Node
{
private:
	ParticleSystemQuad* ballParticle;
	bool launched;

public:
	Ball();
	~Ball();

	void launch(Point mouseCoords);
	void call(Point callTo);

	ParticleSystemQuad* getBallParticle();

	bool isLaunched();
};