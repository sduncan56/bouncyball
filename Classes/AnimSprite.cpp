

#include "AnimSprite.h"

AnimSprite::AnimSprite(std::string filename, int X, int Y)
{

	initWithSpriteFrameName(filename);
	//initWithFile(filename);



	setPosition(X, Y);
	velX = velY = 0;


	auto physicsBody = PhysicsBody::createBox(Size(32, 32), PhysicsMaterial(0.2, 0.1, 0.3));
	physicsBody->setContactTestBitmask(-1);

	setPhysicsBody(physicsBody);
	getPhysicsBody()->setDynamic(true);


	alive = true;



}

AnimSprite::~AnimSprite()
{

}

void AnimSprite::walk()
{
	setPositionX(getPositionX() + velX);
}

void AnimSprite::kill()
{
	alive = false;

}

bool AnimSprite::isAlive()
{
	return alive;
}