#include "Animal.h"
#include "MapManager.h"
#include "Plant.h"

Animal::Animal(int x, int y, MapArrayType* map) : ActiveMapEntity(x, y, map, constants::ANIMAL_START_ENERGY) {};

MapEntityType Animal::getType()
{
	return MapEntityType::animal;
}

void Animal::drawSign()
{
	cout << "\33[0;91;49m" << (char)(64 + this->energy) << "\033[0m";
}

void Animal::onTick()
{
	// loose energy and check if you should die
	this->energy--;

	if (this->energy == 0) {
		MapManager::clearFrom(*this->mapPointer, this->x, this->y);
		return;
	}

	int newX;
	int newY;
	// eating plant if is nearby
	for (int dx = -1; dx <= 1; dx++){
		for (int dy = -1; dy <= 1; dy++){
			newX = this->x + dx;
			newY = this->y + dy;
			// check if at next cells there is no plant to eat
			if ((dx == 0 && dy==0) || !MapManager::positionInMap(newX, newY)) continue;
			// eat that plant
			Plant* possiblePlant = dynamic_cast<Plant*>((*this->mapPointer)[newX][newY]);
			if (possiblePlant == nullptr) continue;

			this->energy += possiblePlant->getEnergy();
			possiblePlant->onEaten();
			if ((*this->mapPointer)[newX][newY] == nullptr) {
				MapManager::moveTo(*this->mapPointer, this->x, this->y, newX, newY);
			}
			return;
		}
	}

	// normal move
	int infinityProtector = 8*10;
	while (infinityProtector > 0){
		infinityProtector--;

		newX = this->x + floor(randomDouble(-1., 2.));
		newY = this->y + floor(randomDouble(-1., 2.));
		if ((newX == this->x && newY == this->y) || !MapManager::positionInMap(newX, newY)) continue;

		MapManager::moveTo(*this->mapPointer, this->x, this->y, newX, newY);
		break;
	}
}
