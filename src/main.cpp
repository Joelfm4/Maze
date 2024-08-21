#include "maze_generator.h"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    ResetGrid();
    Visit(1, 1);
    PrintGrid();

    return 0;
}

