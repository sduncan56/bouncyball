


#include "Enemy.h"

Enemy::Enemy(std::string filename, int X, int Y) : AnimSprite(filename, X, Y)
{
	setName("enemy");

	setFlipX(true);

	scheduler = new Scheduler();

	schedule(schedule_selector(Enemy::shoot), 1.0f);
}

Enemy::~Enemy()
{
	for (auto bullet : bullets)
	{
		bullet->release();
	}

	delete scheduler;

}

void Enemy::shoot(float f)
{
	if (!alive) return;

	int xDir = 1;
	if (isFlippedX())
		xDir = -1;

	getPhysicsBody()->getPosition().x;
	auto bullet = new Bullet(getPhysicsBody()->getPosition().x, getPhysicsBody()->getPosition().y, xDir);
	//auto bullet = new Bullet(getPositionX(), getPositionY(), xDir);
	Director::getInstance()->getRunningScene()->addChild(bullet);
	bullets.push_back(bullet);

	auto audio = CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("shot.wav", false, 1.0f, 0.0f, 0.1f);


}