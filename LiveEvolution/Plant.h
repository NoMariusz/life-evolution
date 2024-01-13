#pragma once
#include "main.h"
#include "ActiveMapEntity.h"

class Plant : public ActiveMapEntity
{
	int growProgress;
public:
	Plant(int x, int y, MapArrayType* map);

	virtual MapEntityType getType() ;
	virtual void drawSign();
	virtual void onTick();
};

