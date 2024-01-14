#include "MapFileLoader.h"
#include "Animal.h"
#include "Plant.h"
#include <fstream>

using namespace std;

bool MapFileLoader::load(MapArrayType& map)
{
	cout << "MapFileLoader: loading map from a file ..." << endl;

	// prepare file stream
	ifstream file;
	file.open(constants::SAVE_FILE_NAME, ios::out);

	if (!file.good()) {
		cout << "ERROR: MapFileLoader: file is not good, probably doesn't exists" << endl;
		file.close();
		return false;
	}

	// check if map size in file is proper(when map is greater in file that is in application end loading)
	int fileMapWidth, fileMapHeight;
	file >> fileMapWidth;
	file >> fileMapHeight;
	if (fileMapWidth > constants::MAP_WIDTH || fileMapHeight > constants::MAP_HEIGHT) {
		cout << "ERROR: MapFileLoader: cannot load a greater map from a file" << endl;
		file.close();
		return false;
	}

	// load each entity
	int type;
	while (file >> type) {
		switch ((MapEntityType)type) {
			case animal:
				MapFileLoader::createEntityInMap<Animal>(map, file);
				break;
			case plant:
				MapFileLoader::createEntityInMap<Plant>(map, file);
				break;
			default:
				cout << "WARNING: MapFileLoader: cannot load a enity of type: " << type << endl;
				file.close();
				return false;
		}
	}

	file.close();
	return true;
}

template<class T>
void MapFileLoader::createEntityInMap(MapArrayType& map, ifstream& file)
{
	T* entity = new T(file, &map);
	map[entity->getX()][entity->getY()] = entity;

}

