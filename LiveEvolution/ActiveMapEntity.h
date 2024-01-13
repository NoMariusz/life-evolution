#pragma once
#include "main.h"
#include "MapEntity.h"

using namespace std;

class ActiveMapEntity : public MapEntity
{
protected:
	MapArrayType* mapPointer;
	int energy;

public:
	int getEnergy();
	ActiveMapEntity(int x, int y, MapArrayType* map, int energy);
	virtual void onTick() = 0;
};

