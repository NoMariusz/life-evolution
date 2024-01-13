#include "MapManager.h"
#include "Plant.h"
#include "Animal.h"
#include "utils.h"
#include <list>

using namespace std;

// generating map

bool MapManager::populateMap(MapArrayType &map) {

	bool success = MapManager::generatePlants(map);
	if (!success) return false;

	success = MapManager::generateAnimals(map);
	if (!success) return false;

	return true;
}

bool MapManager::generatePlants(MapArrayType& map) {
	// generate initial plants count
	int availableCellsCount = constants::MAP_HEIGHT * constants::MAP_WIDTH;
	int plantsCount = int(randomDouble(availableCellsCount * constants::PLANT_INITIAL_GROW_MIN_TILES, availableCellsCount * constants::PLANT_INITIAL_GROW_MAX_TILES));
	return MapManager::addElementsToMap<Plant>(map, plantsCount);
}

bool MapManager::generateAnimals(MapArrayType& map)
{
	// generate initial plants count
	int availableCellsCount = constants::MAP_HEIGHT * constants::MAP_WIDTH;
	int animalsCount = int(randomDouble(availableCellsCount * constants::ANIMAL_INITIAL_PRESENCE_MIN_TILES, availableCellsCount * constants::ANIMAL_INITIAL_PRESENCE_MAX_TILES));
	return MapManager::addElementsToMap<Animal>(map, animalsCount);
}

template <class Entity>
bool MapManager::addElementsToMap(MapArrayType& map, int count) {
	int i = 0;
	int tempCount = count;
	while (tempCount) {
		i++;
		if (i > 10 * constants::MAP_HEIGHT * constants::MAP_WIDTH) {
			cout << "ERROR: MapManager: problem with generating plants, loop cannot generate proper plants count" << endl;
			return false;
		}

		int randomX = int(randomDouble(0, constants::MAP_WIDTH));
		int randomY = int(randomDouble(0, constants::MAP_HEIGHT));

		// chek if cell empty
		if (map[randomX][randomY] != nullptr) continue;

		map[randomX][randomY] = new Entity(randomX, randomY, &map);

		tempCount--;
	}

	return true;
}

// drawing map

void MapManager::drawMap(MapArrayType& map) {
	cout << "\tMap:" << endl;

	for (int i = 0; i < constants::MAP_WIDTH; i++)
	{
		cout << "=";
	}
	cout << endl;


	for (int y = constants::MAP_HEIGHT-1; y >= 0; y--)
	{
		for (auto& column : map) {
			MapEntity*& entity = column[y];
			if (entity == nullptr) {
				cout << " ";
			}
			else {
				entity->drawSign();
			}
		}
		cout << endl;
	}

	for (int i = 0; i < constants::MAP_WIDTH; i++)
	{
		cout << "=";
	}
	cout << endl;
}

// on tick

void MapManager::onTick(MapArrayType& map) {
	MapManager::propagateTickToEntities(map);
	MapManager::generateNewPlants(map);
}

void MapManager::propagateTickToEntities(MapArrayType& map) {
	// store list of animals to later tick them indepently, to not iterate them on original array when animals move senf through the array
	list<Animal*> animals;

	for (auto& column : map) {
		for (MapEntity*& entity : column) {
			ActiveMapEntity* activeEntity = dynamic_cast<ActiveMapEntity*>(entity);
			if (activeEntity != nullptr) {
				if (activeEntity->getType() == animal) {
					animals.push_front((Animal*)activeEntity);
				}
				else {
					activeEntity->onTick();
				}
			}
		}
	}
	for (auto& animal : animals) {
		animal->onTick();
	}
}

bool MapManager::isTherePlant(MapArrayType& map, int x, int y) {
	return MapManager::positionInMap(x, y) && map[x][y] != nullptr &&  map[x][y]->getType() == plant;

}
void MapManager::generateNewPlants(MapArrayType& map) {
	for (size_t x = 0; x < constants::MAP_WIDTH; ++x) {
		for (size_t y = 0; y < constants::MAP_HEIGHT; ++y) {
			MapEntity*& entity = map[x][y];

			if (entity != nullptr) continue;

			// calculate grow chance considering nearby cells
			double chance = constants::PLANT_TICK_GROW_CHANCE;

			for (int i = -1; i <= 1; i += 2) {
				for (int j = -1; i <= 1; i += 2) {
					if (MapManager::isTherePlant(map, x +i, y+j)) {
						chance = constants::PLANT_TICK_GROW_NEAR_PLANT_CHANCE;
					}
				}
			}

			// make random test if plant will grow
			if (randomDouble() > chance) continue;

			// grow new plant
			map[x][y] = new Plant(x, y, &map);
		}
	}
}

// Entities utils

bool MapManager::positionInMap(int x, int y) {
	return x >= 0 && x < constants::MAP_WIDTH && y >= 0 && y < constants::MAP_HEIGHT;
}

void MapManager::moveTo(MapArrayType& map, int fromX, int fromY, int toX, int toY) {
	MapEntity* entity = map[fromX][fromY];
	entity->x = toX;
	entity->y = toY;
	map[toX][toY] = entity;
	map[fromX][fromY] = nullptr;
	return;
}

void MapManager::clearFrom(MapArrayType& map, int x, int y) {
	delete map[x][y];
	map[x][y] = nullptr;
}