#include "maze_generator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

char grid[GRID_WIDTH * GRID_HEIGHT];

void ResetGrid() {
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; ++i) {
        grid[i] = '#';
    }
}

int XYToIndex(int x, int y) {
    return y * GRID_WIDTH + x;
}

bool IsInBounds(int x, int y) {
    return (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT);
}

void Visit(int x, int y) {
    grid[XYToIndex(x, y)] = ' ';

    int dirs[4] = {NORTH, EAST, SOUTH, WEST};
    for (int i = 0; i < 4; ++i) {
        int r = std::rand() & 3;
        std::swap(dirs[i], dirs[r]);
    }

    for (int i = 0; i < 4; ++i) {
        int dx = 0, dy = 0;
        switch (dirs[i]) {
            case NORTH: dy = -1; break;
            case SOUTH: dy = 1; break;
            case EAST: dx = 1; break;
            case WEST: dx = -1; break;
        }
        int x2 = x + (dx << 1);
        int y2 = y + (dy << 1);
        if (IsInBounds(x2, y2) && grid[XYToIndex(x2, y2)] == '#') {
            grid[XYToIndex(x2 - dx, y2 - dy)] = ' ';
            Visit(x2, y2);
        }
    }
}

void PrintGrid() {
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            std::cout << grid[XYToIndex(x, y)];
        }
        std::cout << std::endl;
    }
}

