#include "ActiveMapEntity.h"

ActiveMapEntity::ActiveMapEntity(int x, int y, list<list<MapEntity*>> map) : MapEntity(x, y), mapReference(map) {};
