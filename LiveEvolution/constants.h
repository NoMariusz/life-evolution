#pragma once

namespace constants
{
    static const char* SAVE_FILE_NAME = "map_save.txt";

    const int MAP_WIDTH = 75;
    const int MAP_HEIGHT = 25;

    const int TICK_TIME = 800; // in milliseconds

    // *** Plant

    const int TICKS_TO_PLANT_GROW = 3;
    const int MAX_PLANT_ENERGY = 15;

    // generating

    // percent of available tiles occupied after generating
    const double PLANT_INITIAL_GROW_MIN_TILES = 0.01;
    const double PLANT_INITIAL_GROW_MAX_TILES = 0.03;
    // chaces are in percents as number between 0 and 1
    const double PLANT_TICK_GROW_CHANCE = 0.0005;
    const double PLANT_TICK_GROW_NEAR_PLANT_CHANCE = 0.01;

    // *** Animal

    const int ANIMAL_START_ENERGY = 20;
    // percent of available tiles occupied after generating
    const double ANIMAL_INITIAL_PRESENCE_MIN_TILES = 0.005;
    const double ANIMAL_INITIAL_PRESENCE_MAX_TILES = 0.01;

}