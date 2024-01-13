#pragma once

namespace constants
{
    const int MAP_WIDTH = 40;
    const int MAP_HEIGHT = 15;

    const int TICK_TIME = 1000; // in milliseconds

    // Plant genrating

    // percent of available tiles occupied after generating
    const double PLANT_INITIAL_GROW_MIN_TILES = 0.02;
    const double PLANT_INITIAL_GROW_MAX_TILES = 0.05;
    // chaces are in percents as number between 0 and 1
    const double PLANT_TICK_GROW_CHANCE = 0.01;
    const double PLANT_TICK_GROW_NEAR_PLANT_CHANCE = 0.10;

    // Plant growing
    const int TICKS_TO_PLANT_GROW = 5;
}