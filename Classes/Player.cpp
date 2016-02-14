


#include "Player.h"


Player::Player(std::string filename, int X, int Y) : AnimSprite(filename, X, Y)
{
	speed = Point(100, 0);

	getPhysicsBody()->setRotationEnable(false);
	setName("player");

	float oldX = 0;
}

Player::~Player()
{
}

void Player::input(EventHandler *eventhandler)
{
	if (eventhandler->isKeyPressed(EventKeyboard::KeyCode::KEY_A) || eventhandler->isKeyPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW)) {
		//getPhysicsBody()->setVelocity(Point(-speed.x, 0));
		//getPhysicsBody()->applyForce(Point(-speed.x, 0));
		velX = -2;
	}
	else if (eventhandler->isKeyPressed(EventKeyboard::KeyCode::KEY_D) || eventhandler->isKeyPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW)) {
		//getPhysicsBody()->setVelocity(Point(speed.x, 0));
		//getPhysicsBody()->applyForce(Point(speed.x, 0));
		velX = 2;
	}

	else if ((!eventhandler->isKeyPressed(EventKeyboard::KeyCode::KEY_A) && !eventhandler->isKeyPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW))
		&& (!eventhandler->isKeyPressed(EventKeyboard::KeyCode::KEY_D) && !eventhandler->isKeyPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW))) {
		//getPhysicsBody()->setVelocity(Point(0, 0));
		velX = 0;
	}

	if (eventhandler->isKeyPressed(EventKeyboard::KeyCode::KEY_W) || eventhandler->isKeyPressed(EventKeyboard::KeyCode::KEY_UP_ARROW)) {
		getPhysicsBody()->applyImpulse(Vec2(0, 1000));
	}
}


void Player::walk()
{
	oldX = getPositionX();

	AnimSprite::walk();


}

float Player::getOldX()
{
	return oldX;
}
