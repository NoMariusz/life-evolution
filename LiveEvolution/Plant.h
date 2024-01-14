#pragma once
#include "main.h"
#include "ActiveMapEntity.h"

class Plant : public ActiveMapEntity
{
	int growProgress;
public:
	Plant(int x, int y, MapArrayType* map);
	Plant(ifstream& file, MapArrayType* map);

	MapEntityType getType() ;
	void drawSign();
	void onTick();
	void onEaten();
	virtual void saveSelf(ofstream& file);
};

