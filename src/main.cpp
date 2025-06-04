#include "maze_generator.h"
#include "ray_casting.h"
#include <cstdlib>
#include <ctime>

int main() {
	int maze[mapWidth][mapHeight];

	createMaze(maze);

	// Starting Point
	maze[1][0] = 3;

	// End Point 
	maze[mapWidth-1][mapHeight-2] = 2;
	maze[mapWidth-2][mapHeight-1] = 2;

  runRayCasting(maze);

  return 0;
}

