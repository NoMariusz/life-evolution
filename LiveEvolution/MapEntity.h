#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class MapManager;

enum MapEntityType {none, animal, plant};

class MapEntity
{
	friend class MapManager;

protected:
	int x;
	int y;
public:
	int getX();
	int getY();

	MapEntity(int x, int y);
	MapEntity(ifstream& file);

	virtual MapEntityType getType() = 0;
	virtual void drawSign() = 0;

	virtual void saveSelf(ofstream& file);
};