#pragma once
#include "main.h"

class MapManager
{
	static bool generatePlants(MapArrayType &map);
	static bool generateAnimals(MapArrayType &map);

	template <class T>
	static bool addElementsToMap(MapArrayType &map, int count);
public:
	static bool populateMap(MapArrayType &map);
	static void drawMap(MapArrayType &map);
	static void onTick(MapArrayType &map);
	// moving utils
	static bool positionInMap(MapArrayType &map, int x, int y);
	static void moveTo(MapArrayType &map, int fromX, int fromY, int toX, int toY);
	static void clearFrom(MapArrayType &map, int x, int y);
};

