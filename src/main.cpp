#include "maze_generator.h"
#include "ray_casting.h"
#include <cstdlib>
#include <ctime>

int main() {
	int maze[mapWidth][mapHeight];

	createMaze(maze);
  runRayCasting(maze);

  return 0;
}

