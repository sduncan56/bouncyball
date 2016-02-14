

#pragma once

#include "cocos2d.h"
#include <vector>

#include "Area.h"
#include "Ball.h"
#include "Player.h"
#include "EventHandler.h"
#include "EnemyManager.h"
#include "GameOver.h"

#include "SimpleAudioEngine.h"


USING_NS_CC;

class Game : public cocos2d::Layer
{
private:
	Area* area;

	Ball* ball;
	Player* player;
	EventHandler* eventhandler;
	EnemyManager* enemyManager;

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void update(float delta);

	void onMouseDown(Event* event);
	virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);

	bool onCollision(PhysicsContact& contact);
	

	CREATE_FUNC(Game);
};