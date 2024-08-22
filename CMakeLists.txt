cmake_minimum_required(VERSION 3.10)

project(maze)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)

include_directories(src ${SDL2_INCLUDE_DIRS})

set(SOURCES
    src/main.cpp
    src/maze_generator.cpp
    src/quickcg.cpp
)

add_executable(maze ${SOURCES})

target_link_libraries(maze ${SDL2_LIBRARIES})

