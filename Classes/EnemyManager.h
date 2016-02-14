

#pragma once

#include "cocos2d.h"

#include "Enemy.h"

USING_NS_CC;

class EnemyManager
{
private:
	std::vector<Enemy*> enemies;
	std::vector<ValueMap> spawnPoints;

	Animation* deathAnim;

public:
	EnemyManager();
	~EnemyManager();

	std::vector<Enemy*> spawn();
	void kill(Enemy* enemy);
	void updateDeltaX(float deltaX);

	void addSpawnPoint(ValueMap spawnPoint);
};