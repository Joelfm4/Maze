cmake_minimum_required(VERSION 3.10)
project(Maze)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src ${SDL_INCLUDE_DIRS})

add_executable(maze
  src/main.cpp
  src/ray_casting.cpp
  src/quickcg.cpp
)

target_link_libraries(maze ${SDL_LIBRARIES})

