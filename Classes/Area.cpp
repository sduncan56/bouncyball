


#include "Area.h"

Area::Area()
{

}

Area::~Area()
{
	delete spawnlayer;
	delete meta;
}

TMXTiledMap* Area::loadMap(std::string filename)
{
	tilemap = TMXTiledMap::create(filename);
	spawnlayer = tilemap->objectGroupNamed("spawnlayer");
	meta = tilemap->layerNamed("meta");
	meta->setVisible(false);

	return tilemap;
}

bool Area::checkColTile(Point tileCoord)
{
	int tileGid = meta->getTileGIDAt(tileCoord);
	if (tileGid) {
		Value properties = tilemap->getPropertiesForGID(tileGid);

		auto collision = properties.asValueMap()["Collidable"];
		if (collision.asString() == "True") {
			return true;
		}
	}
	return false;
}

void Area::scrollMap(int deltaX)
{
	tilemap->setPosition((Vec2(tilemap->getPositionX()-deltaX, tilemap->getPositionY())));
}

Vector<Node*> Area::addPhysics()
{
	//physics = Node::create();

	/*auto physicsBody = PhysicsBody::create();
	physicsBody->setDynamic(false);*/

	Vector<Node*> physicsBlocks;

	for (int x = 0; x < tilemap->getMapSize().width; x++)
	{
		for (int y = 0; y < tilemap->getMapSize().height; y++)
		{
			if (checkColTile(Point(x, y)))
			{
				/*auto box = PhysicsShapeBox::create(tilemap->getTileSize(), PhysicsMaterial(1.0f, 1.0f, 0.5f));
			

				physicsBody->addShape(box);*/

				Node* block = Node::create();
				//block->setPosition(Point(x*tilemap->getTileSize().width, y*tilemap->getTileSize().height));
				auto pos = tileToPosCoord(Point(x, y));
				pos.x += 32;
				pos.y -= 32;
				block->setPosition(pos);

				auto physicsBody = PhysicsBody::createBox(tilemap->getTileSize(), PhysicsMaterial(1.0f, 0.9f, 0.5f));
				physicsBody->setDynamic(false);

				block->setPhysicsBody(physicsBody);

				physicsBlocks.pushBack(block);

				//physics->addChild(block);
			}
		}
	}
	//physics->setPhysicsBody(physicsBody);


	return physicsBlocks;
}


ValueMap Area::getSpawnPoint(std::string pointName)
{
	return spawnlayer->getObject(pointName);
}

Point Area::posToTileCoord(Point position)
{
	int x = position.x / tilemap->getTileSize().width;
	int y = ((tilemap->getMapSize().height*tilemap->getTileSize().height) - position.y) / tilemap->getTileSize().height;
	return Point(x, y);
}

Point Area::tileToPosCoord(Point tilePos)
{
	int x = tilePos.x*tilemap->getTileSize().width;
	int y = tilemap->getMapSize().height*tilemap->getTileSize().height - (tilePos.y*tilemap->getTileSize().height);
	return Point(x, y);
}

Vec2 Area::getSize()
{
	return Vec2(tilemap->getMapSize().width*tilemap->getTileSize().width, tilemap->getMapSize().height*tilemap->getTileSize().height);
}