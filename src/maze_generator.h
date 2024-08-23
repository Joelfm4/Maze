#ifndef MAZE_H
#define MAZE_H

#include "ray_casting.h"
#define GRID_WIDTH 24
#define GRID_HEIGHT 24
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3


void ResetGrid();
int XYToIndex(int x, int y);
bool IsInBounds(int x, int y);
void Visit(int x, int y);
void PrintGrid();


void generateMaze(int worldMap[mapWidth][mapHeight]);

#endif // MAZE_H

