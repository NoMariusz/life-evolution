#pragma once
#include "ActiveMapEntity.h"
class Animal : public ActiveMapEntity
{
public:
	Animal(int x, int y, MapArrayType* map);

	MapEntityType getType();
	void drawSign();
	void onTick();
	void saveSelf(ofstream& file);
};

