

#include "GameOver.h"

GameOver::GameOver()
{
	init();

}

bool GameOver::init()
{
	auto label = Label::createWithSystemFont("Game Over", "Arial", 40);
	auto winSize = Director::getInstance()->getWinSizeInPixels();
	label->setPosition(winSize.width / 2, winSize.height / 2);
	addChild(label);

	auto button = ui::Button::create();
	button->setTouchEnabled(true);
	button->loadTextures("retry.png", "retry.png");
	button->setPosition(Point(winSize.width / 2, winSize.height / 2) + Point(0, -50));
	//button->addTouchEventListener(this, toucheventselector(GameOver::retry));
	addChild(button);
	

	return true;
}

void GameOver::update(float delta)
{

}

void GameOver::retry(Event* event)
{

}