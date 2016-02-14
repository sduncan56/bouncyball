

#include "Bullet.h"

Bullet::Bullet(int x, int y, int xDir)
{
	setName("bullet");

	initWithFile("bullet.png");

	auto physicsBody = PhysicsBody::createBox(Size(6, 2), PhysicsMaterial(0.7, 0.1, 0.3));

	physicsBody->setContactTestBitmask(-1);

	setPhysicsBody(physicsBody);

	setPosition(Vec2(x, y));

	getPhysicsBody()->applyImpulse(Vec2(4000*xDir, 0));

	schedule(schedule_selector(Bullet::clean), 2.0f);


}

void Bullet::clean(float f)
{
	removeFromParentAndCleanup(true);
}