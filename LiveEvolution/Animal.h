#pragma once
#include "ActiveMapEntity.h"
class Animal : public ActiveMapEntity
{
public:
	Animal(int x, int y, MapArrayType* map);

	virtual MapEntityType getType();
	virtual void drawSign();
	virtual void onTick();
};

