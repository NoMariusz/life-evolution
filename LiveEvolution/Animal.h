#pragma once
#include "ActiveMapEntity.h"
class Animal : public ActiveMapEntity
{
public:
	Animal(int x, int y, MapArrayType* map);
	Animal(ifstream& file, MapArrayType* map);

	MapEntityType getType();
	void drawSign();
	void onTick();
};

