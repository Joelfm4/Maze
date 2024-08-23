// #include "maze_generator.h"
#include "ray_casting.h"
#include <cstdlib>
#include <ctime>

int main() {

    #if 0
    std::srand(static_cast<unsigned>(std::time(0)));

    ResetGrid();
    Visit(1, 1);
    PrintGrid();
    #endif

    runRayCasting();
    return 0;
}

