#include "App.h"
#include "MapManager.h"
#include <iostream>


using namespace std;

App::App() {
	// initialising a map
	for (auto& row : map) {
		for (MapEntity*& entity : row) {
			entity = nullptr;  // You can initialize with some default value or nullptr
		}
	}
}

void App::start() {
	cout << "Application starting..." << endl;
	// TODO: decision if generate new map or load from a file
	this->generateMap();

	while (1) {
		sleep(constants::TICK_TIME);
		this->onTick();
	}
}

void App::generateMap()
{
	cout << "Generating new map..." << endl;
	MapManager::populateMap(map);
}

void App::onTick()
{
	cout << "Tick..." << endl;
}
