#pragma once
#include <iostream>
#include <array>
#include "constants.h"
#include "utils.h"
#include "MapEntity.h"

using MapArrayType = array<array<MapEntity*, constants::MAP_HEIGHT>, constants::MAP_WIDTH>;