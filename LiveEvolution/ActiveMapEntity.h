#pragma once
#include "MapEntity.h"
#include <list>

using namespace std;

class ActiveMapEntity : public MapEntity
{
	list<list<MapEntity*>> mapReference;

public:
	ActiveMapEntity(int x, int y, list<list<MapEntity*>> map);
	virtual void onTick() = 0;
};

