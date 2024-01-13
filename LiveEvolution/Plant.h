#pragma once
#include "ActiveMapEntity.h"

class Plant : public ActiveMapEntity
{
	int energy;
	int growProgress;
public:
	Plant(int x, int y, list<list<MapEntity*>> map);
	int getEnergy();

	virtual MapEntityType getType() ;
	virtual void drawSign();
	virtual void onTick();
};

