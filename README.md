# Maze

## How does ray casting work?
The map is a 2D square grid, and each square can either be 0 (no wall), or a positive value (a wall with a certain colour or texture).

There are three main components:

- The player

- The player's direction

- The camera plane


## Components representation
![Code](images/vec.png)
- The `white ball` represents the player (vector "pos")
- The `white ray` represents the player's direction (vector "dir")
- The `yellow line` represents the camera "plane"


## Player movement
When the `player rotates`, the camera has to rotate, so both the direction vector and the plane vector have to be rotated.
```
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
```

## How does Maze generation work?
This code uses a Depth-First Search (DFS) algorithm to generate a maze.

1. **Initialization**:

2. **Starting Point**:

3. **DFS Maze Generation**:


Extra
- Timer
- End represented with white walls


## Final result
![Code](images/maze_visual.png)
