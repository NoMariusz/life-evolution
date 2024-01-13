#pragma once
#include "main.h"

class MapManager
{
	static bool generatePlants(MapArrayType &map);
	static bool generateAnimals(MapArrayType &map);

	template <class T>
	static bool addElementsToMap(MapArrayType &map, int count);

	static void propagateTickToEntities(MapArrayType &map);
	static void generateNewPlants(MapArrayType &map);
	static bool isTherePlant(MapArrayType &map, int x, int y);
public:
	static bool populateMap(MapArrayType &map);
	static void drawMap(MapArrayType &map);
	static void onTick(MapArrayType &map);
	// moving utils
	static bool positionInMap(int x, int y);
	static void moveTo(MapArrayType &map, int fromX, int fromY, int toX, int toY);
	static void clearFrom(MapArrayType &map, int x, int y);
};

