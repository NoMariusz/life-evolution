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
};

