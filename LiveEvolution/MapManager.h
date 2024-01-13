#pragma once
#include "main.h"

class MapManager
{
	static bool generatePlants(MapArrayType &map);
public:
	static bool populateMap(MapArrayType &map);
	static void drawMap(MapArrayType &map);
};

