#pragma once
#include "main.h"

class MapFileLoader
{
	template <class T>
	static void createEntityInMap(MapArrayType& map, ifstream& file);
public:
	static bool load(MapArrayType& map);
};