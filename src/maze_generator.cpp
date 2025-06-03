#include "maze_generator.h"
#include "ray_casting.h"

// y -> Line (row)
// x -> Column
void printMaze(int (&maze)[mapHeight][mapWidth]){
    for(int y = 0; y < mapHeight; ++y){
        for(int x = 0; x < mapWidth; ++x){
            std::cout << maze[y][x];
        }
        std::cout << '\n';
    }
}

bool isInside(int x, int y){
    return (0 <= x && x < mapWidth) && (0 <= y && y < mapHeight);
}

void carveMaze(int (&maze)[mapHeight][mapWidth], int x, int y){
    int directions[4][2] = {{2,0}, {-2,0}, {0,2}, {0,-2}};

    maze[y][x] = 0;

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(directions), std::end(directions), g);
    
    for(const auto& direction : directions){
        int dx = direction[0];
        int dy = direction[1];
        int nx = x + dx;
        int ny = y + dy;
        
        if(isInside(nx, ny) && maze[ny][nx] == 1){
            maze[y + dy/2][x + dx/2] = 0;
            carveMaze(maze, nx, ny);
        }
    }
}

void createMaze(int (&maze)[mapHeight][mapWidth]){
    // Initialize the array
    for(int y = 0; y < mapHeight; ++y){
        for(int x = 0; x < mapWidth; ++x){
            maze[y][x] = 1;
        }
    }
    carveMaze(maze, 1, 1);
    printMaze(maze);
}
