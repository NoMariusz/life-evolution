#include "Animal.h"

Animal::Animal(int x, int y, MapArrayType* map) : ActiveMapEntity(x, y, map, constants::ANIMAL_START_ENERGY) {};

MapEntityType Animal::getType()
{
	return MapEntityType::animal;
}

void Animal::drawSign()
{
	cout << "\33[0;91;49m" << this->energy << "\033[0m";
}

void Animal::onTick()
{
	this->energy--;
}
