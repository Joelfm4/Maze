#include <cmath>
#include <cstdlib>
#include <string>
#include "ray_casting.h"

int worldMap[mapWidth][mapHeight]
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

void runRayCasting()
{

  double posX = 12, posY = 12;      // Start position
  double dirX = -1, dirY = 0;       // Initial direction vector
  double planeX = 0, planeY = 0.66; // 2d raycaster version of camera plane

  // FPS variables
  double time = 0;    // Time of current frame
  double oldTime = 0; // Time of previous frame

  // Screen Resolution
  screen(screenWidth, screenHeight, 0, "Maze");

  // Game Loop
  while(!done()){
    for(int x = 0; x < screenWidth; x++)
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
      int stepX = 0;
      int stepY = 0;

      int hit = 0;
      int side;

      // Calculate step
      if(rayDirX < 0){
        stepX = -1;
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
      int lineHeight = (int)(h / perpWallDist);

      // Calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + h / 2;
      if(drawStart < 0) drawStart = 0;

      int drawEnd = lineHeight / 2 + h / 2;
      if(drawEnd >= h) drawEnd = h - 1;


      // Wall color
      ColorRGB color;
      switch (worldMap[mapX][mapY]) {
        case 1: color = RGB_Red; break;     // Red
        case 2: color = RGB_Green; break;   // Green
        case 3: color = RGB_Blue; break;    // Blue
        case 4: color = RGB_White; break;   // White
        default: color = RGB_Yellow; break;
      }

      // Give x and y sides different brightness
      if(side == 1) {color = color / 2;}

      // Draw the pixels of the stripe as a vertical line
      verLine(x, drawStart, drawEnd, color);
    }
    // Timing for input and FPS counter
    oldTime = time;
    time = getTicks();
      
    double frameTime = (time - oldTime) / 1000.0; // In seconds
    print(1.0 / frameTime);                  // FPS counter
    redraw();                                     // Redraw the screen
    cls();                                        // Clean the backbuffer

    // Speed modifiers
    double moveSpeed = frameTime * 5.0; // The constant value is in squares / second
    double rotSpeed = frameTime * 3.0;  // The constant value is in radians / second


    // Player movement
    readKeys();
    if (keyDown(SDLK_UP)){
      if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;

    }

    // Move backwards
    if (keyDown(SDLK_DOWN)){
      if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    }

    // Rotate to the right
    if (keyDown(SDLK_RIGHT)){
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }

    // Rotate to the left
    if (keyDown(SDLK_LEFT)){
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }

}




 }
