#include "MapEntity.h"


int MapEntity::getX() {
	return this->x;
}

int MapEntity::getY() {
	return this->y;
}

MapEntity::MapEntity(int x, int y) : x(x), y(y) {}

MapEntity::MapEntity(ifstream& file)
{
	file >> this->x;
	file >> this->y;
}

void MapEntity::saveSelf(ofstream& file)
{
	file << this->x << " " << this->y << " ";
}
;
