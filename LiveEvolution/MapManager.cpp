#include "MapManager.h"
#include "Plant.h"
#include "Animal.h"
#include "utils.h"

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

		Entity* newEntity = new Entity(randomX, randomY, &map);
		map[randomX][randomY] = newEntity;

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
	// clearing dead entities
	for (auto& row : map) {
		for (MapEntity*& entity : row) {
			ActiveMapEntity* activeEntity = dynamic_cast<ActiveMapEntity*>(entity);
			if (activeEntity != nullptr) {
				if (activeEntity->getEnergy() == 0) {
					delete entity;
					entity = nullptr;
				}
			}
		}
	}
}