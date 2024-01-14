#include "ActiveMapEntity.h"

ActiveMapEntity::ActiveMapEntity(int x, int y, MapArrayType* map, int energy) : MapEntity(x, y), mapPointer(map), energy(energy) {}

ActiveMapEntity::ActiveMapEntity(ifstream& file, MapArrayType* map) : MapEntity(file)
{
    this->mapPointer = map;
    file >> this->energy;
}

void ActiveMapEntity::saveSelf(ofstream& file)
{
    MapEntity::saveSelf(file);
    file << this->energy << " ";
}
;

int ActiveMapEntity::getEnergy()
{
    return this->energy;
}