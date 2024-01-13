#include "Plant.h"
#include <iostream>

using namespace std;

Plant::Plant(int x, int y, MapArrayType* map) : ActiveMapEntity(x, y, map), energy(1), growProgress(0) {};

int Plant::getEnergy()
{
    return this->energy;
}

MapEntityType Plant::getType() {
    return MapEntityType::plant;
}

void Plant::drawSign() {
    cout << "Plant is drawing sign...";
}

void Plant::onTick() {
    cout << "Plant is performing onTick...";
}
