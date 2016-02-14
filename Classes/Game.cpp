

#include "Game.h"

Scene* Game::createScene()
{
	auto scene = Scene::createWithPhysics();
	auto layer = Game::create();

	scene->addChild(layer);
	return scene;
}

bool Game::init()
{
	if (!Layer::init())
	{
		return false;
	}

	area = new Area();
	addChild(area->loadMap("map.tmx"), 0, "corridor");
	auto physicsBlocks = area->addPhysics();
	for (auto block : physicsBlocks)
	{
		addChild(block);
	}

	ValueMap spawnPoint = area->getSpawnPoint("PlayerSpawnPoint");

	SpriteBatchNode* playerBatch = SpriteBatchNode::create("playersheet.png");
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("playersheet.plist");

	player = new Player("player01.png", spawnPoint["x"].asInt()+32, spawnPoint["y"].asInt()+64);
	addChild(player);

	eventhandler = new EventHandler();
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventhandler->initKeyboard(), this);
	
	//ball

	ball = new Ball();

	addChild(ball);
	ball->setPosition(Point(player->getPositionX() + 12, player->getPositionY() - 8));


	//enemy

	SpriteBatchNode* spritebatch = SpriteBatchNode::create("enemysheet.png");
	cache->addSpriteFramesWithFile("enemysheet.plist");



	enemyManager = new EnemyManager();

	char str[100] = { 0 };
	for (int i = 1; i < 9; i++)
	{
		sprintf(str, "esp%d", i);
		enemyManager->addSpawnPoint(area->getSpawnPoint(str));
	}
	
	auto enemies = enemyManager->spawn();
	for (auto enemy : enemies)
	{
		addChild(enemy);
	}
	addChild(spritebatch);


	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Game::onCollision, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	Point origin = Director::sharedDirector()->getVisibleOrigin();
	Size size = Director::sharedDirector()->getVisibleSize();
	Point centre = Point(size.width / 2 + origin.x, size.height / 2 + origin.y);

	float playfield_width = area->getSize().x;
	float playfield_height = size.height;
	
	this->runAction(Follow::create(player, Rect(0, 0, playfield_width, playfield_height)));


	//auto listener = EventListenerTouchAllAtOnce::create();
	auto listener = EventListenerMouse::create();
	listener->onMouseDown = CC_CALLBACK_1(Game::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	schedule(schedule_selector(Game::update));

	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bgm.wav", true);

	//addChild(new GameOver());

	return true;
}

void Game::onMouseDown(Event* event)
{
	EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);

	if (mouseEvent->getMouseButton() == 0)
	{
		ball->launch(mouseEvent->getLocation());
	}
	else if (mouseEvent->getMouseButton() == 1)
	{
		ball->call(Point(player->getPositionX() + 12, player->getPositionY() - 8));
		//ball->call(Point(player->getPhysicsBody()->getPosition().x + 12, player->getPhysicsBody()->getPosition().y - 8));
	}

	
}

bool Game::onCollision(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();

	if ((nodeA->getName() == "ball") && (nodeB->getName() == "player"))
	{
		return false;
	}
	if ((nodeA->getName() == "ball") && (nodeB->getName() == "enemy"))
	{
		Enemy* enemy = dynamic_cast<Enemy*>(nodeB);
		
		enemyManager->kill(enemy);

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("death.wav");
	}
	if (nodeA->getName() == "bullet" && nodeB->getName() != "enemy")
	{
		Bullet* bullet = dynamic_cast<Bullet*>(nodeA);
		bullet->clean(1);
	}

	return true;
	
}

void Game::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
	EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);

	ball->launch(mouseEvent->getLocationInView());
}


void Game::update(float delta)
{
	player->input(eventhandler);
	player->walk();

	float deltaX = player->getPositionX() - player->getOldX();
	
	
	if (!ball->isLaunched())
	{
		//ball->setPosition(Point(player->getPhysicsBody()->getPosition().x + 12, player->getPhysicsBody()->getPosition().y - 8));
		ball->setPosition(Point(player->getPositionX()+12, player->getPositionY() - 8));
	}

}