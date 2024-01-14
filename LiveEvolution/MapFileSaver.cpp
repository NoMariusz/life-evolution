#include "MapFileSaver.h"
#include <fstream>


using namespace std;


void MapFileSaver::save(MapArrayType& map)
{
	cout << "MapFileSaver: saving map to a file ..." << endl;

	// prepare file stream
	ofstream file;
	file.open("map_save.txt", ios::in | ios::trunc);

	// save map size
	file << constants::MAP_WIDTH << " " << constants::MAP_HEIGHT << endl;

	// save each entity
	for (auto& column : map) {
		for (MapEntity*& entity : column) {
			if (entity != nullptr) {
				entity->saveSelf(file);
			}
		}
	}

	file.close();
}
