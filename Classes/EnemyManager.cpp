

#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();


	Vector<SpriteFrame*> animFrames(4);
	char str[100] = { 0 };
	for (int i = 1; i < 4; i++)
	{
		sprintf(str, "enemy%02d.png", i);
		SpriteFrame* frame = cache->getSpriteFrameByName(str);
		animFrames.pushBack(frame);
	}

	deathAnim = Animation::createWithSpriteFrames(animFrames, 0.2f);
	deathAnim->retain();
}

EnemyManager::~EnemyManager()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		delete enemies.at(i);
	}
}



std::vector<Enemy*> EnemyManager::spawn()
{
	for (auto spawnPoint : spawnPoints)
	{
		auto enemy = new Enemy("enemy01.png", spawnPoint["x"].asInt() + 32, spawnPoint["y"].asInt() + 32);
		enemies.push_back(enemy);


	}

	return enemies;
}

void EnemyManager::kill(Enemy* enemy)
{
	if (!enemy->isAlive()) return;
	enemy->runAction(Animate::create(deathAnim));
	enemy->kill();

	/*for (auto e : enemies)
	{
		if (e == enemy)
		{
			
		}
	}*/
}

void EnemyManager::updateDeltaX(float deltaX)
{
	for (auto enemy : enemies)
	{
		enemy->setPosition((Vec2(enemy->getPositionX() - deltaX, enemy->getPositionY())));
	}
}

void EnemyManager::addSpawnPoint(ValueMap spawnPoint)
{
	spawnPoints.push_back(spawnPoint);

}