#ifndef MAZE_H
#define MAZE_H

#define GRID_WIDTH 24
#define GRID_HEIGHT 24
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

extern char grid[GRID_WIDTH * GRID_HEIGHT];

void ResetGrid();
int XYToIndex(int x, int y);
bool IsInBounds(int x, int y);
void Visit(int x, int y);
void PrintGrid();

#endif // MAZE_H

