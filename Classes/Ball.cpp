

#include "Ball.h"

Ball::Ball()
{
	launched = false;

	ballParticle = ParticleSystemQuad::create("ball.plist");

	auto physicsBody = PhysicsBody::createCircle(9, PhysicsMaterial(0.1f, 1.0f, 0.2f));
	//physicsBody->setDynamic(false);


	physicsBody->setGravityEnable(false);
	physicsBody->setContactTestBitmask(-1);

	setPhysicsBody(physicsBody);
	setName("ball");
	addChild(ballParticle);




}

Ball::~Ball()
{

}

void Ball::launch(Point mouseCoords)
{
	if (launched) return;

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("balllaunch.wav");


	auto winSize = Director::sharedDirector()->getWinSizeInPixels();

	auto pos = getPhysicsBody()->getPosition();// getPosition();

	//I am not sure why the height-space that the mouse is operating in is twice as big as the screen
	//there should be a better way to fix this, but this seems to work
	mouseCoords.y = winSize.height*2 - mouseCoords.y; 

	//mouseCoords = this->convertToNodeSpace(mouseCoords);

	Vec2 movement = mouseCoords - pos;

	if (movement.x != 0 && movement.y != 0)
		movement.normalize();


	
	getPhysicsBody()->applyImpulse(movement*10000);
	getPhysicsBody()->setGravityEnable(true);

	launched = true;
}

void Ball::call(Point callTo)
{
	launched = false;
	setPosition(callTo);
	getPhysicsBody()->resetForces();
	getPhysicsBody()->setVelocity(Vec2(0, 0));
	getPhysicsBody()->setGravityEnable(false);
}

ParticleSystemQuad* Ball::getBallParticle()
{
	return ballParticle;
}

bool Ball::isLaunched()
{
	return launched;
}