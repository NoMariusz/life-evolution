#pragma once
#include "main.h"
#include "MapEntity.h"

using namespace std;

class ActiveMapEntity : public MapEntity
{
	MapArrayType* mapPointer;

public:
	ActiveMapEntity(int x, int y, MapArrayType* map);
	virtual void onTick() = 0;
};

