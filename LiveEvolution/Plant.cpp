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
    cout << "\33[0;32;49m"  << this->energy << "\033[0m";
}

void Plant::onTick() {
    growProgress++;
    if (growProgress > constants::TICKS_TO_PLANT_GROW) {
        this->energy++;
        growProgress = 0;
    }
}
