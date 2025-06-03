#ifndef MAZE_H
#define MAZE_H

#include "ray_casting.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>

void printMaze(int (&maze)[mapWidth][mapHeight]);
bool isInside(int x, int y);

void carveMaze(int (&maze)[mapWidth][mapHeight], int x, int y);
void createMaze(int (&maze)[mapWidth][mapHeight]);

#endif // MAZE_H

