#ifndef RAY_CASTING_H
#define RAY_CASTING_H

// Define constants
const int screenWidth = 640;
const int screenHeight = 480;
const int mapWidth = 24;
const int mapHeight = 24;


#include "quickcg.h"
using namespace QuickCG;


extern int worldMap[mapWidth][mapHeight];


void runRayCasting();

#endif

