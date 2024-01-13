#include "MapManager.h"
#include "Plant.h"
#include "utils.h"

using namespace std;

bool MapManager::populateMap(MapArrayType &map) {
	bool success = MapManager::generatePlants(map);
	if (!success) return false;

	return true;
}

bool MapManager::generatePlants(MapArrayType& map) {
	// generate initial plants count
	int availableCellsCount = constants::MAP_HEIGHT * constants::MAP_WIDTH;
	int plantsCount = int(randomDouble(availableCellsCount * constants::PLANT_INITIAL_GROW_MIN_TILES, availableCellsCount * constants::PLANT_INITIAL_GROW_MAX_TILES));
	int i = 0;
	while (plantsCount) {
		i++;
		if (i > 10 * availableCellsCount) {
			cout << "ERROR: MapManager: problem with generating plants, loop cannot generate proper plants count" << endl;
			return false;
		}

		int randomX = int(randomDouble(0, constants::MAP_WIDTH));
		int randomY = int(randomDouble(0, constants::MAP_HEIGHT));

		// chek if cell empty
		if (map[randomX][randomY] != nullptr) continue;

		Plant newPlant = Plant(randomX, randomY, &map);
		map[randomX][randomY] = &newPlant;

		plantsCount--;
	}

	return true;
}