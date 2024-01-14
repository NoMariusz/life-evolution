#include "App.h"
#include "MapManager.h"
#include "ActiveMapEntity.h"
#include "Animal.h"
#include "MapFileSaver.h"
#include <iostream>
#include <windows.h>
#include <Winuser.h>

#define ASCI_CODE_S 83


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
		// check if user want to save
		if (GetAsyncKeyState(ASCI_CODE_S)) {
			MapFileSaver::save(this->map);
		}
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
