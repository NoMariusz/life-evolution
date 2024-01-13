#pragma once
#include "main.h"

using namespace std;

class App
{
	MapArrayType map;
	void generateMap();
public:
	App();

	void start();
	void onTick();
};

