#include "App.h"
#include "MapManager.h"
#include "ActiveMapEntity.h"
#include "Animal.h"
#include <iostream>


using namespace std;

App::App() {
	for (auto& row : map) {
		for (MapEntity*& entity : row) {
			entity = nullptr;
		}
	}
}

void App::start() {
	cout << "Application starting..." << endl;

	// init needed things like random generator seed
	srand(time(NULL));

	// TODO: decision if generate new map or load from a file
	this->generateMap();

	MapManager::drawMap(map);

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

	MapManager::onTick(map);
	MapManager::drawMap(map);
}
