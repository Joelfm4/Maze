cmake_minimum_required(VERSION 3.10)


project(maze)


set(CMAKE_CXX_STANDARD 11)


include_directories(src)


set(SOURCES
    src/main.cpp
    src/maze_generator.cpp
)


add_executable(maze ${SOURCES})

