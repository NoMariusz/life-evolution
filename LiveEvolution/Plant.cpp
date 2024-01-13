#include "Plant.h"
#include <iostream>
#include "MapManager.h"

using namespace std;

Plant::Plant(int x, int y, MapArrayType* map) : ActiveMapEntity(x, y, map, 1), growProgress(0) {};

MapEntityType Plant::getType() {
    return MapEntityType::plant;
}

void Plant::drawSign() {
    cout << "\33[0;32;49m"  << hex << this->energy << "\033[0m";
}

void Plant::onTick() {
    growProgress++;
    if (growProgress > constants::TICKS_TO_PLANT_GROW) {
        this->energy++;
        growProgress = 0;
    }
}

void Plant::onEaten() {
    this->energy = 0;
    MapManager::clearFrom(*this->mapPointer, this->x, this->y);
}
