# Maze


## How does ray casting work?
The map is a 2D square grid, and each square can either be 0 (no wall), or a positive value (a wall with a certain colour or texture).

There are three main components:

- The player represented as a vector (x and y coordinates).

- The player's direction is represented as a vector (x and y coordinates).

- A camera plane, which represents the surface of the computer screen and is represented by a line (a single vector) that should always be perpendicular to the direction vector.





## Components representation
![Code](images/vec.png)
- The `white ball` represents the player (vector "pos")
- The `white ray` represents the player's direction (vector "dir")
- The `yellow line` represents the camera "plane". (I will use quotes around "plane" because ray casting occurs on a 2D map, so the plane is essentially just a line. However, for clarity, I will refer to it as the camera plane, even though this terminology isn’t entirely accurate.)





## DDA(Digital Differential Analysis)

We used `Digital Differential Analysis (DDA)` to find which squares of the map the ray hits and stop the algorithm once a square that is a wall is hit.
![Code](images/DDA.png)

[Super Fast Ray Casting in Tiled Worlds using DDA](https://youtu.be/NbSee-XM7WA?si=yP9j_d1tot5lHzC1)





## FOV (Field Of Vision)
The FOV is `determinated by the ratio of the length of the direction vector, and the length of the plane`
### Example: 

<div style="display: flex; justify-content: center;">
    <img src="images/fov_ex.png" alt="Example FOV" width="500" height="500" style="margin-right: 10px;">
    <img src="images/fov.webp" alt="FOV Diagram" width="500" height="500">
</div>
In the example on the right, the concept of FOV becomes clearer. Generally, a larger FOV results in a wider field of view.





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
   - The `grid` is reset to all walls (`1`) with `ResetGrid()`.

2. **Starting Point**:
   - The maze generation starts from a given cell, typically `(1, 1)`.

3. **DFS Maze Generation (`Visit` function)**:
   - Mark the current cell as visited (`0`).
   - Randomly shuffle the directions (NORTH, EAST, SOUTH, WEST) to ensure randomness.
   - For each direction, check if moving two steps in that direction is within bounds and leads to an unvisited cell.
     - If so, remove the wall between the current cell and the new cell and recursively visit the new cell.

4. **Grid Conversion (`GenerateWorldMap` function)**:
   - Convert the generated grid into the world map format.





## Final result
![Code](images/maze_visual.png)
