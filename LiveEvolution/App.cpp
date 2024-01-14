#include "App.h"
#include "MapManager.h"
#include "ActiveMapEntity.h"
#include "Animal.h"
#include "MapFileSaver.h"
#include "MapFileLoader.h"
#include <iostream>
#include <windows.h>
#include <Winuser.h>

#define ASCI_CODE_S 83


using namespace std;

App::App() {
	// prepare map structure
	for (auto& row : map) {
		for (MapEntity*& entity : row) {
			entity = nullptr;
		}
	}

	// change streams work to enable buffering control https://stackoverflow.com/questions/796865/can-i-stop-stdcout-flushing-on-n
	std::ios_base::sync_with_stdio(false);
}

void App::start() {
	cout << "Application starting..." << endl;
	cout << "\tTo save actual map to a file press 's'" << endl;
	cout << endl;

	// init needed things like random generator seed
	srand(time(NULL));

	// decision if generate new map or load from a file
	char sign;
	cout << "Please, give a letter:\n\t'l' - if you want to load map from a file \n\tanything different - when you want to generate a new map" << endl;
	cin >> sign;
	if (sign == 'l') {
		bool success = MapFileLoader::load(this->map);
		if (!success) return;
	}
	else {
		this->generateMap();
	}

	// draw map and start main loop
	MapManager::drawMap(map);

	while (1) {
		sleep(constants::TICK_TIME);

		// check if user want to save
		if (GetAsyncKeyState(ASCI_CODE_S)) {
			MapFileSaver::save(this->map);
		}

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
