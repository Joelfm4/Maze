#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

#include "quickcg.h"
using namespace QuickCG;

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main(int /*argc*/, char */*argv*/[])
{

  double posX = 22, posY = 12;      // Start position
  double dirX = -1, dirY = 0;       // Initial direction vector
  double planeX = 0, planeY = 0.66; // 2d raycaster version of camera plane

  // FPS variables
  double time = 0;    // Time of current frame
  double oldTime = 0; // Time of previous frame

  // Screen Resolution
  screen(screenWidth, screenHeight, 0, "Maze");

  // Game Loop
  while(!done()){
    for(int x = 0; x < w; x++)
    {
      // Calculate tay position and direction
      double cameraX = 2 * x / double(w) - 1;    // x-cordinate in camera space
      double rayDirX = dirX + planeX * cameraX;  // Ray direction
      double rayDirY = dirY + planeY * cameraX;  // Ray direction
      
      // Which box of the map we're in
      int mapX = int(posX);
      int mapY = int(posY);

      // Length of the ray from CURRENT position to next x or y-side
      double sideDistX;
      double sideDistY;
      
      // Length of ray from one x or y-side to next x or y-side (depend on ray angle)
      double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
      double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
      double perpWallDist;

      // Steps directions
      int stepX;
      int stepY;

      int hit = 0;
      int side;

      // Calculate step
      if(rayDirX < 0){
        stepX -= 1;
        sideDistX = (posX - mapX) * deltaDistX;

      }else{
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }

      if(rayDirY < 0){
        stepY -= 1;
        sideDistY = (posY - mapY) * deltaDistY;
      }else{
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }


      // DDA ALgorithm
      while(hit == 0){

        // Jump to next map square (angle tells where)
        if(sideDistX < sideDistY){
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;

        }else{
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;

        }
        if(worldMap[mapX][mapY] > 0) hit = 1;
      }

      // Calculate distance projected on camera direction
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);


      // Calculate height of line to draw on scren
    }
  }




 }
