#pragma once
#include "main.h"
#include "ActiveMapEntity.h"

class Plant : public ActiveMapEntity
{
	int growProgress;
public:
	Plant(int x, int y, MapArrayType* map);

	MapEntityType getType() ;
	void drawSign();
	void onTick();
	void onEaten();
	void saveSelf(ofstream& file);
};

