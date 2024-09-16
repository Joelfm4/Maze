# Maze


## How does ray casting work?
The map is a 2D square grid, and each square can either be 0 (no wall), or a positive value (a wall with a certain colour or texture).

There are three main components:

- The player represented as a vector (x and y coordinates).

- The player's direction is represented as a vector (x and y coordinates).

- A camera plane, which represents the surface of the computer screen and is represented by a line (a single vector) that should always be perpendicular to the direction vector.


### DDA(Digital Differential Analysis)

We used **Digital Differential Analysis (DDA)** to find which squares of the map the ray hits and stop the algorithm once a square that is a wall is hit.

![Code](images/DDA.png)


### FOV (Field Of Vision)
![Code](images/vec.png)
The FOV is determinated by the ratio of the length of the direction vector, and the length of the plane
Example: 
...
...
![Code](https://www.reddit.com/media?url=https%3A%2F%2Fpreview.redd.it%2Fk0910qp964j21.jpg%3Fwidth%3D1080%26crop%3Dsmart%26auto%3Dwebp%26s%3Dcdba385b6843c8c120a581bb2533cea4a8c814e5)


## How does Maze generation work?
...
...
...



## Final result
![Code](images/maze_visual.png)
