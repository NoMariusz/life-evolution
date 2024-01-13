#pragma once

class MapManager;

enum MapEntityType {animal, plant};

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

	virtual MapEntityType getType() = 0;
	virtual void drawSign() = 0;
};