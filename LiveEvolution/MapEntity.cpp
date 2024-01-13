#include "MapEntity.h"


int MapEntity::getX() {
	return this->x;
}

int MapEntity::getY() {
	return this->y;
}

MapEntity::MapEntity(int x, int y) : x(x), y(y) {};
