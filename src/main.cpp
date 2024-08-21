#include <iostream>
#include <cstdlib>
#include <ctime>

#define GRID_WIDTH 79
#define GRID_HEIGHT 23
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Global variable representing the grid of the maze
char grid[GRID_WIDTH * GRID_HEIGHT];

// Function prototypes
void ResetGrid();
int XYToIndex(int x, int y);
bool IsInBounds(int x, int y);
void Visit(int x, int y);
void PrintGrid();

int main() {
    // Seed the random number generator for maze generation
    std::srand(static_cast<unsigned>(std::time(0)));

    // Initialize the grid with walls
    ResetGrid();

    // Start maze generation from the initial position (1,1)
    Visit(1, 1);

    // Print the generated maze
    PrintGrid();

    return 0;
}

// Initialize the grid with walls ('#')
void ResetGrid() {
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; ++i) {
        grid[i] = '#';
    }
}

// Convert (x, y) coordinates to a single-dimensional index
int XYToIndex(int x, int y) {
    return y * GRID_WIDTH + x;
}

// Check if the coordinates (x, y) are within the bounds of the grid
bool IsInBounds(int x, int y) {
    return (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT);
}

// Recursive function to generate the maze
void Visit(int x, int y) {
    // Mark the current cell as a passage (' ')
    grid[XYToIndex(x, y)] = ' ';

    // Array to hold the four possible directions (NORTH, EAST, SOUTH, WEST)
    int dirs[4] = {NORTH, EAST, SOUTH, WEST};

    // Shuffle directions to randomize the maze generation
    for (int i = 0; i < 4; ++i) {
        int r = std::rand() & 3;  // Random index for shuffling
        std::swap(dirs[i], dirs[r]);
    }

    // Explore each direction
    for (int i = 0; i < 4; ++i) {
        int dx = 0, dy = 0;
        switch (dirs[i]) {
            case NORTH: dy = -1; break;
            case SOUTH: dy = 1; break;
            case EAST: dx = 1; break;
            case WEST: dx = -1; break;
        }

        // Calculate the coordinates of the cell two steps away in the current direction
        int x2 = x + (dx << 1);
        int y2 = y + (dy << 1);

        // Check if the new position is within bounds and has not been visited
        if (IsInBounds(x2, y2) && grid[XYToIndex(x2, y2)] == '#') {
            // Remove the wall between the current cell and the new cell
            grid[XYToIndex(x2 - dx, y2 - dy)] = ' ';
            // Recursively visit the new cell
            Visit(x2, y2);
        }
    }
}

// Print the maze to the console
void PrintGrid() {
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            std::cout << grid[XYToIndex(x, y)];
        }
        std::cout << std::endl;
    }
}

