#include "ActiveMapEntity.h"

ActiveMapEntity::ActiveMapEntity(int x, int y, MapArrayType* map, int energy) : MapEntity(x, y), mapPointer(map), energy(energy) {};

int ActiveMapEntity::getEnergy()
{
    return this->energy;
}