

#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Area
{
private:
	TMXTiledMap* tilemap;
	TMXObjectGroup* spawnlayer;
	TMXLayer* meta;

	Node* physics;

public:
	Area();
	~Area();
	TMXTiledMap* loadMap(std::string filename);

	bool checkColTile(Point position);

	void scrollMap(int deltaX);

	Vector<Node*> addPhysics();
	ValueMap getSpawnPoint(std::string pointName);

	Point posToTileCoord(Point position);
	Point tileToPosCoord(Point tilePos);

	Vec2 getSize();

};