#include "maze_generator.h"
#include "maze_generator.h"
#include "ray_casting.h"
#include <cstdlib>
#include <ctime>

int main() {
  int worldMap[GRID_WIDTH][GRID_HEIGHT];
  generateMaze(worldMap);
  runRayCasting(worldMap);

  return 0;
}

